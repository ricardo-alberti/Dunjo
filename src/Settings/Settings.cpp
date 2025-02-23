#include "Settings.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <stdexcept>
#include <unordered_map>
#include <vector>

Settings *Settings::Instance;

Settings::Settings() {
  if (!texture.loadFromFile("../assets/sprites/blacknwhite.png")) {
    throw std::runtime_error("Failed to load texture");
  }

  std::vector<std::pair<std::string, sf::IntRect>> spriteData = {
      {"Middle", sf::IntRect({12, 12}, {12, 12})},
      {"TopMiddle", sf::IntRect({12, 0}, {12, 12})},
      {"LeftWall", sf::IntRect({0, 12}, {12, 12})},
      {"Slab", sf::IntRect({24, 48}, {12, 12})},
      {"Player", sf::IntRect({36, 0}, {12, 12})},
      {"Chain", sf::IntRect({84, 24}, {12, 12})},
      {"Chest", sf::IntRect({36, 12}, {12, 12})},
      {"Coin", sf::IntRect({0, 60}, {12, 12})},
      {"Computer", sf::IntRect({60, 48}, {12, 12})},
      {"Door", sf::IntRect({84, 12}, {12, 12})},
      {"Fire", sf::IntRect({36, 24}, {12, 12})},
      {"Grave", sf::IntRect({48, 12}, {12, 12})},
      {"Key", sf::IntRect({60, 12}, {12, 12})},
      {"Ladder", sf::IntRect({36, 48}, {12, 12})},
      {"MagicBrick", sf::IntRect({48, 24}, {12, 12})},
      {"TopLeftCorner", sf::IntRect({0, 0}, {12, 12})},
      {"TopRightCorner", sf::IntRect({24, 0}, {12, 12})},
      {"BottomMiddle", sf::IntRect({12, 24}, {12, 12})},
      {"BottomLeftCorner", sf::IntRect({0, 24}, {12, 12})},
      {"BottomRightCorner", sf::IntRect({24, 24}, {12, 12})},
      {"RightWall", sf::IntRect({24, 12}, {12, 12})}
  };

  for (const auto &sprite : spriteData) {
    spritesMap.emplace(sprite.first, sf::Sprite(texture, sprite.second));
  }
}

const sf::Texture &Settings::getTexture() const { return texture; }
const sf::Sprite &Settings::getSprite(std::string spriteName) const {
  return spritesMap.at(spriteName);
}

Settings *Settings::getInstance() {
  if (Instance == nullptr) {
    Instance = new Settings();
  }

  return Instance;
}
