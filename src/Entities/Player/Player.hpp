#pragma once

#include "../../Settings/Settings.hpp"
#include "../../Utils/Animation/Animation.hpp"
#include "../../Utils/HitBoxSprite/HitBoxSprite.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <memory>

using func = std::function<void(float)>;
enum PlayerState { Idle, Running, Jumping, Climbing, Dead };

class Player {
private:
  inline static sf::Sprite sprite = sf::Sprite(
      Settings::getInstance()->getTexture(), sf::IntRect(36, 0, 12, 12));

  std::shared_ptr<HitBoxSprite> hitBoxSprite =
      std::make_shared<HitBoxSprite>(sprite, 0, 0, 8, 10, sf::Vector2f(3, 0));

  PlayerState playerState = PlayerState::Idle;
  int score;
  bool onGround = false;
  float verticalVelocity;
  float horizontalVelocity;
  float jumpCooldownPassed;
  int keys;

  std::unique_ptr<Animation> idleAnimation =
      std::make_unique<Animation>(hitBoxSprite, 36, 0, 0, 1);
  std::unique_ptr<Animation> jumpAnimation =
      std::make_unique<Animation>(hitBoxSprite, 48, 0, 0.1f, 1);
  std::unique_ptr<Animation> runAnimation =
      std::make_unique<Animation>(hitBoxSprite, 36, 0, 0.1f, 4);
  std::unique_ptr<Animation> deadAnimation =
      std::make_unique<Animation>(hitBoxSprite, 84, 0, 0.2f, 1);

  std::unordered_map<PlayerState, func> animations{
      {PlayerState::Idle,
       [this](float _deltaTime) { idleAnimation->update(_deltaTime); }},
      {PlayerState::Running,
       [this](float _deltaTime) { runAnimation->update(_deltaTime); }},
      {PlayerState::Dead,
       [this](float _deltaTime) { deadAnimation->update(_deltaTime); }},
      {PlayerState::Jumping,
       [this](float _deltaTime) { jumpAnimation->update(_deltaTime); }}
  };

  void moveRight(float _deltaTime);
  void moveLeft(float _deltaTime);
  void jump(float _deltaTime);
  void blockPlayerWorldLimit();
  void setForce(float _horizontalForce, float _verticalForce);
  void resetVerticalVelocity();
  void resetHorizontalVelocity();

public:
  Player();
  HitBoxSprite &getHitBoxSprite();

  void blockLeftMovement(float x);
  void blockRightMovement(float x);
  void blockDownMovement(float y);
  void blockUpMovement(float y);

  void Update(float _deltaTime);
  bool useKey();
  void getKey();
  void increaseScore(int _points);
  void takeDamage();
  void climb();
  bool goDownSlab();
};
