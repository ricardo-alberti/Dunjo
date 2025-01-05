#pragma once

#include "../../Settings/Settings.hpp"
#include "../../Utils/Animation/Animation.hpp"
#include "../../Utils/HitBoxSprite/HitBoxSprite.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

class Tile;

class Player {
private:
  const float JUMP_FORCE = -300.f;
  const float JUMP_COOLDOWN = 0.05f;
  const float MOVEMENT_SPEED = 100.0f;
  const float GRAVITY = 1900.0f;
  const float SCALE_X = 1.0f;
  const float SCALE_Y = 1.0f;

  inline static sf::Sprite sprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(36, 0, 12, 10));

  float jumpCooldownPassed;

  std::shared_ptr<HitBoxSprite> hitBoxSprite;
  std::unique_ptr<Animation> idleAnimation;
  std::unique_ptr<Animation> jumpAnimation;
  std::unique_ptr<Animation> runAnimation;
  std::unique_ptr<Animation> deadAnimation;

  bool defeated;
  int score;
  float verticalVelocity;
  bool isJumping;

  void moveRight(float _deltaTime);
  void moveLeft(float _deltaTime);
  void jump(float _deltaTime);

public:
  Player(int x, int y);
  const HitBoxSprite &getSprite() const;
  void Update(float _deltaTime);
  void handleCollision(Tile &tile);
  void setForce(float _force);
  void increaseScore(int _points);
  void die();
};
