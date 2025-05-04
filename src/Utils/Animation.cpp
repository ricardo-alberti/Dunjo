#include "Utils/Animation.hpp"
#include <memory>

Animation::Animation(std::shared_ptr<HitBoxSprite> _sprite, int initialFrame_X,
                     int initialFrame_Y, float _frameTime, int _numFrames)
    : sprite(_sprite), initialFrame_X(initialFrame_X),
      initialFrame_Y(initialFrame_Y), frameTime(_frameTime), currentFrame(0),
      elapsedTime(0.0f) {
  for (int i = 0; i < _numFrames; ++i) {
    frames.emplace_back(
        sf::Vector2<int>(initialFrame_X + i * frameWidth, initialFrame_Y),
        sf::Vector2<int>(frameWidth, frameHeight));
  }
}

const void Animation::update(float deltaTime) {
  elapsedTime += deltaTime;

  if (elapsedTime >= frameTime) {
    elapsedTime -= frameTime;
    currentFrame = (currentFrame + 1) % frames.size();
    sprite->setTextureRect(frames[currentFrame]);
  }
}

const void Animation::reset() { currentFrame = 0; }
