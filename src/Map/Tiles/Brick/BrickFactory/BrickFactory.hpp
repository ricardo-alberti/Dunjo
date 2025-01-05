#pragma once

#include "../../TileFactory/TileFactory.hpp"
#include <memory>

class BrickFactory : public TileFactory {
public:
  std::shared_ptr<Tile> createTile(TileType tileType, float x,
                                   float y) override;
};
