#include "Player.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

constexpr float WORLD_LIMIT_LEFT = 0;
constexpr float WORLD_LIMIT_RIGHT = 22 * 12;
constexpr float IDLE_SPEED = 30.0;
constexpr float JUMP_FORCE = -300.f;
constexpr float JUMP_COOLDOWN = 0.07f;
constexpr float MOVEMENT_SPEED = 800.0f;
constexpr float CLIMB_SPEED = -250.0f;
constexpr float HORIZONTAL_RESISTANCE = 8.0f;
constexpr float GRAVITY = 1900.0f;
constexpr float SCALE_X = 1.0f;
constexpr float SCALE_Y = 1.0f;

Player::Player() { hitBoxSprite->setOrigin(6, 0); }

HitBoxSprite &Player::getHitBoxSprite() { return *hitBoxSprite; }
void Player::resetVerticalVelocity() { verticalVelocity = 0; }
void Player::resetHorizontalVelocity() { horizontalVelocity = 0; }
void Player::increaseScore(int _points) { score += _points; }
void Player::climb() {
  playerState = PlayerState::Jumping;
  setForce(horizontalVelocity, CLIMB_SPEED);
}

void Player::blockPlayerWorldLimit() {
  if (hitBoxSprite->getPosition().x >= WORLD_LIMIT_RIGHT) {
    hitBoxSprite->setPosition(WORLD_LIMIT_RIGHT, hitBoxSprite->getPosition().y);
  } else if (hitBoxSprite->getPosition().x <= WORLD_LIMIT_LEFT) {
    hitBoxSprite->setPosition(WORLD_LIMIT_LEFT, hitBoxSprite->getPosition().y);
  }
}

void Player::resetToCheckPoint(sf::Vector2f checkPoint) {
  resetVerticalVelocity();
  resetHorizontalVelocity();

  hitBoxSprite->setPosition(checkPoint.x, checkPoint.y);
  playerState = PlayerState::Idle;
  score = 0;
  keys = 0;
}

void Player::Update(float _deltaTime) {
  if (lastState != playerState) {
    lastState = playerState;
    animations.at(playerState).reset();
  }

  animations.at(playerState).update(_deltaTime);

  blockPlayerWorldLimit();

  hitBoxSprite->move(horizontalVelocity * _deltaTime,
                     verticalVelocity * _deltaTime);
  verticalVelocity += GRAVITY * _deltaTime;
  horizontalVelocity -= horizontalVelocity * HORIZONTAL_RESISTANCE * _deltaTime;

  if (playerState == PlayerState::Dead)
    return;

  // set state if idle
  if (horizontalVelocity <= IDLE_SPEED && horizontalVelocity >= -IDLE_SPEED &&
      onGround)
    playerState = PlayerState::Idle;

  // input
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    moveLeft(_deltaTime);
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    moveRight(_deltaTime);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && onGround)
    jump(_deltaTime);
}

void Player::moveRight(float _deltaTime) {
  if (onGround)
    playerState = PlayerState::Running;

  horizontalVelocity += MOVEMENT_SPEED * _deltaTime;
  hitBoxSprite->setScale(sf::Vector2(SCALE_X, SCALE_Y));
}

void Player::moveLeft(float _deltaTime) {
  if (onGround)
    playerState = PlayerState::Running;

  horizontalVelocity -= MOVEMENT_SPEED * _deltaTime;
  hitBoxSprite->setScale(sf::Vector2(-SCALE_X, SCALE_Y));
}

void Player::jump(float _deltaTime) {
  jumpCooldownPassed += _deltaTime;

  if (jumpCooldownPassed >= JUMP_COOLDOWN) {
    verticalVelocity = JUMP_FORCE;
    playerState = PlayerState::Jumping;
    jumpCooldownPassed = 0.0f;
    onGround = false;
  }
}

bool Player::goDownSlab() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    playerState = PlayerState::Jumping;
    return true;
  }

  return false;
}

bool Player::useKey() {
  if (keys > 0) {
    keys--;
    return true;
  }

  return false;
}

void Player::getKey() { keys++; }

void Player::takeDamage() {
  if (playerState == PlayerState::Dead)
    return;

  setForce(-horizontalVelocity, JUMP_FORCE);
  playerState = PlayerState::Dead;
}

void Player::setForce(float _horizontalForce, float _verticalForce) {
  verticalVelocity = _verticalForce;
  horizontalVelocity = _horizontalForce;
}

void Player::blockUpMovement(float y) {
  hitBoxSprite->setPosition(hitBoxSprite->getPosition().x, y);
}
void Player::blockLeftMovement(float x) {
  hitBoxSprite->setPosition(x, hitBoxSprite->getPosition().y);
}
void Player::blockRightMovement(float x) {
  hitBoxSprite->setPosition(x, hitBoxSprite->getPosition().y);
}
void Player::blockDownMovement(float y) {
  if (verticalVelocity < 0)
    return;

  resetVerticalVelocity();
  hitBoxSprite->setPosition(hitBoxSprite->getPosition().x, y);
  onGround = true;
}
