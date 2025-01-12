#pragma once

#include "../../Tiles/Chain/Chain.hpp"
#include "../../Tiles/Chest/Chest.hpp"
#include "../../Tiles/Coin/Coin.hpp"
#include "../../Tiles/Computer/Computer.hpp"
#include "../../Tiles/Door/Door.hpp"
#include "../../Tiles/Fire/Fire.hpp"
#include "../../Tiles/Grave/Grave.hpp"
#include "../../Tiles/Key/Key.hpp"
#include "../../Tiles/Ladder/Ladder.hpp"
#include "../BrickFactory/BrickFactory.hpp"
#include <memory>

class CentralTileFactory {
private:
  const BrickFactory brickFactory = BrickFactory();

public:
  std::shared_ptr<Tile> createTile(TileType type, float x, float y) const {
    if (type == TileType::Fire) {
      return std::make_shared<class Fire>(x, y, Fire::fireSprite);
    }
    if (type == TileType::Coin) {
      return std::make_shared<class Coin>(x, y, Coin::coinSprite);
    }
    if (type == TileType::Chain) {
      return std::make_shared<class Chain>(x, y);
    }
    if (type == TileType::Door) {
      return std::make_shared<class Door>(x, y);
    }
    if (type == TileType::Ladder) {
      return std::make_shared<class Ladder>(x, y);
    }
    if (type == TileType::Grave) {
      return std::make_shared<class Grave>(x, y);
    }
    if (type == TileType::Computer) {
      return std::make_shared<class Computer>(x, y, Computer::computerSprite);
    }
    if (type == TileType::Chest) {
      return std::make_shared<class Chest>(x, y);
    }
    if (type == TileType::Key) {
      return std::make_shared<class Key>(x, y);
    }

    return brickFactory.createTile(type, x, y);
  }
};
