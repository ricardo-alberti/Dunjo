#pragma once

#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Utils/Animation.hpp"
#include <memory>

class AnimatedTile : public Tile {
public:
  AnimatedTile(float x, float y, std::shared_ptr<HitBoxSprite> sprite)
      : Tile(x, y, sprite) {
    animated = true;
  }

  virtual ~AnimatedTile() {};
  virtual void Update(float deltaTime) = 0;
};
