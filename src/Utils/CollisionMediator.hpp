#pragma once

#include "Entities/Player.hpp"
#include "Tiles/Tile.hpp"
#include <memory>

class CollisionMediator {
private:
  const float COLLISION_MARGIN = 1.0f;

public:
  void checkCollisions(Player &player,
                       const std::vector<std::shared_ptr<Tile>> &tiles);
  void handleDirectionalCollisions(Tile &tile, Player &player);
  void handleSlabCollisions(Tile &tile, Player &player);
};
