#include "Player.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

Player::Player(int _x, int _y)
    : verticalVelocity(0.0f), isJumping(true), defeated(false) {
  hitBoxSprite =
      std::make_shared<HitBoxSprite>(sprite, _x, _y, 8, 10, sf::Vector2f(3, 0));
  hitBoxSprite->setOrigin(6, 0);
  hitBoxSprite->setPosition(_x, _y);

  idleAnimation = std::make_unique<Animation>(hitBoxSprite, 36, 0, 0, 1);
  jumpAnimation = std::make_unique<Animation>(hitBoxSprite, 48, 0, 0.1f, 1);
  runAnimation = std::make_unique<Animation>(hitBoxSprite, 36, 0, 0.1f, 4);
  deadAnimation = std::make_unique<Animation>(hitBoxSprite, 84, 0, 0.2f, 1);
}

HitBoxSprite &Player::getHitBoxSprite() { return *hitBoxSprite; }

void Player::Update(float _deltaTime) {
  // gravidade
  hitBoxSprite->move(0, verticalVelocity * _deltaTime);
  verticalVelocity += GRAVITY * _deltaTime;

  // derrotado
  if (defeated) {
    deadAnimation->update(_deltaTime);
    return;
  }

  // input
  bool isMoving = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    moveLeft(_deltaTime);
    isMoving = true;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    moveRight(_deltaTime);
    isMoving = true;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isJumping) {
    jump(_deltaTime);
  }

  if (isJumping) {
    jumpAnimation->update(_deltaTime);
  } else if (!isMoving) {
    idleAnimation->update(_deltaTime);
  } else {
    runAnimation->update(_deltaTime);
  }
}

void Player::moveRight(float _deltaTime) {
  if (hitBoxSprite->getPosition().x >= WORLD_LIMIT_RIGHT)
    return;

  hitBoxSprite->setScale(SCALE_X, SCALE_Y);
  hitBoxSprite->move(MOVEMENT_SPEED * _deltaTime, 0);
}

void Player::moveLeft(float _deltaTime) {
  if (hitBoxSprite->getPosition().x <= WORLD_LIMIT_LEFT)
    return;

  hitBoxSprite->setScale(-SCALE_X, SCALE_Y);
  hitBoxSprite->move(-MOVEMENT_SPEED * _deltaTime, 0);
}

void Player::jump(float _deltaTime) {
  jumpCooldownPassed += _deltaTime;

  if (jumpCooldownPassed >= JUMP_COOLDOWN) {
    verticalVelocity = JUMP_FORCE;
    isJumping = true;
    jumpCooldownPassed = 0.0f;
  }
}

void Player::increaseScore(int _points) { score += _points; }

void Player::climb() { setForce(JUMP_FORCE); }

bool Player::goDownSlab() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    return true;
  }

  return false;
}

void Player::takeDamage() {
  if (defeated)
    return;

  setForce(JUMP_FORCE);
  defeated = true;
}

void Player::setForce(float _force) { verticalVelocity = _force; }

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

  verticalVelocity = 0;
  hitBoxSprite->setPosition(hitBoxSprite->getPosition().x, y);
  isJumping = false;
}
