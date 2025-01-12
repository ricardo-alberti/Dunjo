#pragma once

#include "../../Tiles/Tile.hpp"
#include <memory>

enum TileType {
  Empty = 0,
  BrickTopLeftCorner = 10,
  BrickTopMiddle = 11,
  BrickTopRightCorner = 12,
  BrickRightWall = 13,
  BrickMiddle = 14,
  BrickLeftWall = 15,
  BrickBottomLeftCorner = 16,
  BrickBottomMiddle = 17,
  BrickBottomRightCorner = 18,
  Fire = 19,
  Coin = 20,
  Door = 21,
  Ladder = 22,
  Computer = 23,
  Chain = 24,
  Grave = 25,
  Chest = 26,
  BrickSlab = 27,
  MagicBrick = 28,
  Key = 29,
};

class TileFactory {
public:
  virtual std::shared_ptr<Tile> createTile(TileType tileType, float x,
                                           float y) const = 0;
};
