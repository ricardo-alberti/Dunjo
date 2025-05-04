#pragma once

#include "Tile.hpp"
#include "Utils/SoundManager.hpp"
#include <cmath>
#include <memory>

class Key : public Tile {
private:
  inline static sf::Sprite sprite = Settings::getInstance()->getSprite("Key");
  Player *playerInstance = nullptr;
  bool taken = false;
  float followSpeed = 100.0f;
  float minDistance = 10.0f;

public:
  Key(float _x, float _y)
      : Tile(_x, _y, std::make_shared<HitBoxSprite>(sprite, _x, _y)) {}

  const HitBoxSprite &getSprite() const { return *hitBoxSprite; }

  void Update(float deltaTime) override {
    if (playerInstance && !playerInstance->keys) {
      hitBoxSprite->setPosition(0, -100000);
      return;
    }

    if (taken && playerInstance) {
      sf::Vector2f keyPos = hitBoxSprite->getPosition();
      sf::Vector2f playerPos = playerInstance->getHitBoxSprite().getPosition();

      float dx = playerPos.x - keyPos.x;
      float dy = playerPos.y - keyPos.y;
      float distance = std::sqrt(dx * dx + dy * dy);

      if (distance > minDistance) {
        float moveX = (dx / distance) * followSpeed * deltaTime;
        float moveY = (dy / distance) * followSpeed * deltaTime;
        hitBoxSprite->move(moveX, moveY);
      }
    }
  }

  const void handleCollision(Player &player) override {
    if (!taken) {
      player.getKey();
      SoundManager::getInstance().play("coin");
      taken = true;
      playerInstance = &player;
    }
  }
};
