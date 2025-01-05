#pragma once

#include "../../Map/Tiles/Tile.hpp"
#include "../../Entities/Player/Player.hpp"
#include <memory>

class CollisionManager {
public:
  static void checkCollisions(Player &player,
                              const std::vector<std::shared_ptr<Tile>> &tiles);
};
