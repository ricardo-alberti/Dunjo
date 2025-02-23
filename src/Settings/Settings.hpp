#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <unordered_map>

class Settings {
private:
  sf::Texture texture;
  static Settings *Instance;
  std::unordered_map<std::string, sf::Sprite> spritesMap;
  Settings();

public:
  const sf::Texture &getTexture() const;
  const sf::Sprite &getSprite(std::string) const;
  static Settings *getInstance();
};
