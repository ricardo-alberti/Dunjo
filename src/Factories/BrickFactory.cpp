#include "Factories/BrickFactory.hpp"
#include "Tiles/Brick.hpp"
#include "Tiles/BrickSlab.hpp"
#include "Tiles/MagicBrick.hpp"
#include <memory>

std::shared_ptr<Tile> BrickFactory::createTile(TileType tileType, float x,
                                               float y) const {
  switch (tileType) {
  case (TileType::BrickMiddle):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("Middle"));
  case (TileType::BrickTopMiddle):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("TopMiddle"));
  case (TileType::BrickTopLeftCorner):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("TopMiddle"));
  case (TileType::BrickTopRightCorner):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("TopRightCorner"));
  case (TileType::BrickBottomMiddle):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("BottomMiddle"));
  case (TileType::BrickBottomLeftCorner):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("BottomLeftCorner"));
  case (TileType::BrickBottomRightCorner):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("BottomRightCorner"));
  case (TileType::BrickLeftWall):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("LeftWall"));
  case (TileType::BrickRightWall):
    return std::make_shared<Brick>(
        x, y, Settings::getInstance()->getSprite("RightWall"));
  case (TileType::BrickSlab):
    return std::make_shared<class BrickSlab>(
        x, y, Settings::getInstance()->getSprite("Slab"));
  case (TileType::MagicBrick):
    return std::make_shared<class MagicBrick>(x, y);
  default:
    return nullptr;
  }
}
