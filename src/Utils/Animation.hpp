#pragma once

#include "Utils/HitBoxSprite.hpp"
#include <memory>
#include <vector>

class Animation {
private:
  const int frameWidth = 12;
  const int frameHeight = 12;

  int initialFrame_X;
  int initialFrame_Y;
  std::shared_ptr<HitBoxSprite> sprite;
  std::vector<sf::IntRect> frames;
  float frameTime;
  int currentFrame;
  float elapsedTime;

public:
  Animation(std::shared_ptr<HitBoxSprite> sprite, int initialFrame_X,
            int initialFrame_Y, float frameTime, int numFrames);
  const void update(float deltaTime);
  const void reset();
};
