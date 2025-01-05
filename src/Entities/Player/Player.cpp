#include "Player.hpp"
#include "../../Map/Tiles/Tile.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

Player::Player(int _x, int _y)
    : verticalVelocity(0.0f), isJumping(true), defeated(false) {
  hitBoxSprite =
      std::make_shared<HitBoxSprite>(sprite, _x, _y, 8, 8, sf::Vector2f(3, 2));
  hitBoxSprite->setOrigin(6, 0);

  idleAnimation = std::make_unique<Animation>(hitBoxSprite, 36, 0, 0, 1);
  jumpAnimation = std::make_unique<Animation>(hitBoxSprite, 48, 0, 0.1f, 1);
  runAnimation = std::make_unique<Animation>(hitBoxSprite, 36, 0, 0.1f, 4);
  deadAnimation = std::make_unique<Animation>(hitBoxSprite, 84, 0, 0.2f, 1);
}

const HitBoxSprite &Player::getSprite() const { return *hitBoxSprite; }

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
  hitBoxSprite->setScale(SCALE_X, SCALE_Y);
  hitBoxSprite->move(MOVEMENT_SPEED * _deltaTime, 0);
}

void Player::moveLeft(float _deltaTime) {
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

void Player::die() {
  if (defeated)
    return;

  setForce(JUMP_FORCE);
  defeated = true;
}

void Player::setForce(float _force) { verticalVelocity = _force; }

void Player::handleCollision(Tile &tile) {
  const sf::FloatRect playerBounds = hitBoxSprite->getGlobalBounds();
  const sf::FloatRect tileBounds = tile.getSprite().getGlobalBounds();

  if (playerBounds.top + playerBounds.height - 7.0f <= tileBounds.top) {
    if (verticalVelocity < 0)
      return;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && tile.climbable) {
      hitBoxSprite->move(0, 1.0f);
      tile.collidable = false;
      return;
    }

    hitBoxSprite->setPosition(hitBoxSprite->getPosition().x,
                              tileBounds.top - playerBounds.height + 2.0f);
    verticalVelocity = 0;
    isJumping = false;
  } else if (tileBounds.top + tileBounds.height - 7.0f <= playerBounds.top) {
    hitBoxSprite->setPosition(hitBoxSprite->getPosition().x,
                              tileBounds.top + tileBounds.height - 2.0f);
  } else if (playerBounds.left < tileBounds.left) {
    hitBoxSprite->setPosition(tileBounds.left - playerBounds.width / 2 + 3.0f,
                              hitBoxSprite->getPosition().y);
  } else if (playerBounds.left + playerBounds.width >
             tileBounds.left + tileBounds.width) {
    hitBoxSprite->setPosition(tileBounds.left + playerBounds.width / 2 - 3.0f +
                                  tileBounds.width,
                              hitBoxSprite->getPosition().y);
  }
}
