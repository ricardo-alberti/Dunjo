#pragma once

#include "Utils/Settings.hpp"
#include "Utils/Animation.hpp"
#include "Utils/HitBoxSprite.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <memory>

using func = std::function<void(float)>;
enum PlayerState { Idle, Running, Jumping, Dead, Climbing };

class Player {
private:
  inline static sf::Sprite sprite =
      Settings::getInstance()->getSprite("Player");

  std::shared_ptr<HitBoxSprite> hitBoxSprite =
      std::make_shared<HitBoxSprite>(sprite, 0, 0, 8, 10, sf::Vector2f(3, 0));

  PlayerState playerState = PlayerState::Idle;
  PlayerState lastState = PlayerState::Idle;
  int score;
  bool onGround = false;
  float jumpCooldownPassed;

  std::unordered_map<PlayerState, Animation> animations{
      {PlayerState::Idle, Animation(hitBoxSprite, 36, 0, 0, 1)},
      {PlayerState::Jumping, Animation(hitBoxSprite, 48, 0, 0, 1)},
      {PlayerState::Climbing, Animation(hitBoxSprite, 60, 0, 0.2f, 2)},
      {PlayerState::Running, Animation(hitBoxSprite, 36, 0, 0.065f, 4)},
      {PlayerState::Dead, Animation(hitBoxSprite, 84, 0, 0.2f, 1)}};

  void moveRight(float _deltaTime);
  void moveLeft(float _deltaTime);
  void jump(float _deltaTime);
  void blockPlayerWorldLimit();
  void resetVerticalVelocity();
  void resetHorizontalVelocity();

public:
  Player();
  HitBoxSprite &getHitBoxSprite();

  float verticalVelocity;
  float horizontalVelocity;
  int keys;

  void blockLeftMovement(float x);
  void blockRightMovement(float x);
  void blockDownMovement(float y);
  void blockUpMovement(float y);

  void resetToCheckPoint(sf::Vector2f checkPoint);
  void setForce(float _horizontalForce, float _verticalForce);
  void addForce(float _horizontalForce, float _verticalForce);
  void Update(float _deltaTime);
  bool useKey();
  void getKey();
  void increaseScore(int _points);
  void takeDamage();
  void climb();
  bool goDownSlab();
};
