#pragma once

#include "../Brick/BrickFactory/BrickFactory.hpp"
#include "../Chain/Chain.hpp"
#include "../Chest/Chest.hpp"
#include "../Coin/Coin.hpp"
#include "../Computer/Computer.hpp"
#include "../Door/Door.hpp"
#include "../Fire/Fire.hpp"
#include "../Grave/Grave.hpp"
#include "../Ladder/Ladder.hpp"
#include <memory>

class CentralTileFactory {
public:
  std::shared_ptr<Tile> createTile(TileType type, float x, float y) const {
    BrickFactory brick = BrickFactory();

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

    return brick.createTile(type, x, y);
  }
};
