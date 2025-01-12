#include "BrickFactory.hpp"
#include "../../Tiles/Brick/Brick.hpp"
#include "../../Tiles/BrickSlab/BrickSlab.hpp"
#include "../../Tiles/MagicBrick/MagicBrick.hpp"
#include <memory>

namespace BrickSprites {
    sf::Sprite Middle            = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(12, 12, 12, 12));
    sf::Sprite TopMiddle         = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(12, 0, 12, 12));
    sf::Sprite TopLeftCorner     = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(0, 0, 12, 12));
    sf::Sprite TopRightCorner    = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(24, 0, 12, 12));
    sf::Sprite BottomMiddle      = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(12, 24, 12, 12));
    sf::Sprite BottomLeftCorner  = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(0, 24, 12, 12));
    sf::Sprite BottomRightCorner = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(24, 24, 12, 12));
    sf::Sprite RightWall         = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(24, 12, 12, 12));
    sf::Sprite LeftWall          = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(0, 12, 12, 12));
    sf::Sprite Slab              = sf::Sprite(Settings::getInstance()->getTexture(), sf::IntRect(24, 48, 12, 12));
} // namespace BrickSprites

std::shared_ptr<Tile> BrickFactory::createTile(TileType tileType, float x,
                                               float y) const {
  switch (tileType) {
  case (TileType::BrickMiddle):
    return std::make_shared<Brick>(x, y, BrickSprites::Middle);
  case (TileType::BrickTopMiddle):
    return std::make_shared<Brick>(x, y, BrickSprites::TopMiddle);
  case (TileType::BrickTopLeftCorner):
    return std::make_shared<Brick>(x, y, BrickSprites::TopLeftCorner);
  case (TileType::BrickTopRightCorner):
    return std::make_shared<Brick>(x, y, BrickSprites::TopRightCorner);
  case (TileType::BrickBottomMiddle):
    return std::make_shared<Brick>(x, y, BrickSprites::BottomMiddle);
  case (TileType::BrickBottomLeftCorner):
    return std::make_shared<Brick>(x, y, BrickSprites::BottomLeftCorner);
  case (TileType::BrickBottomRightCorner):
    return std::make_shared<Brick>(x, y, BrickSprites::BottomRightCorner);
  case (TileType::BrickLeftWall):
    return std::make_shared<Brick>(x, y, BrickSprites::LeftWall);
  case (TileType::BrickRightWall):
    return std::make_shared<Brick>(x, y, BrickSprites::RightWall);
  case (TileType::BrickSlab):
    return std::make_shared<class BrickSlab>(x, y, BrickSprites::Slab);
  case (TileType::MagicBrick):
    return std::make_shared<class MagicBrick>(x, y);
  default:
    return nullptr;
  }
}
