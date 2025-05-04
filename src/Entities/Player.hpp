#pragma once

#include "Utils/Animation.hpp"
#include "Utils/HitBoxSprite.hpp"
#include "Utils/Settings.hpp"
#include <functional>
#include <memory>

using func = std::function<void(float)>;
enum PlayerState { Idle, Running, Jumping, Dead, Climbing };

class Player {
private:
  inline static sf::Sprite sprite = Settings::getInstance()->getSprite("Player");
  std::shared_ptr<HitBoxSprite> hitBoxSprite = std::make_shared<HitBoxSprite>(sprite, 0, 0, 8, 10, sf::Vector2f(3, 0));
  std::unordered_map<PlayerState, Animation> animationsMap;

  float jumpCooldownPassed;
  PlayerState playerState;
  PlayerState lastState;
  int coinsTakenPerMap;
  bool onGround;

  void moveRight(float _deltaTime);
  void moveLeft(float _deltaTime);
  void jump(float _deltaTime);

  void blockPlayerWorldLimit();
  void resetVerticalVelocity();
  void resetHorizontalVelocity();
  void updateVelocity(float _deltaTime);

public:
  Player();
  HitBoxSprite &getHitBoxSprite();

  float verticalVelocity;
  float horizontalVelocity;
  int score;
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
