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
    switch (type) {
    case TileType::Fire:
      return std::make_shared<class Fire>(x, y, Fire::fireSprite);

    case TileType::Coin:
      return std::make_shared<class Coin>(x, y, Coin::coinSprite);

    case TileType::Chain:
      return std::make_shared<class Chain>(x, y);

    case TileType::Door:
      return std::make_shared<class Door>(x, y);

    case TileType::Ladder:
      return std::make_shared<class Ladder>(x, y);

    case TileType::Grave:
      return std::make_shared<class Grave>(x, y);

    case TileType::Computer:
      return std::make_shared<class Computer>(x, y, Computer::computerSprite);

    case TileType::Chest:
      return std::make_shared<class Chest>(x, y);

    case TileType::Key:
      return std::make_shared<class Key>(x, y);

    default:
      return brickFactory.createTile(type, x, y);
    }
  }
};
