#include "Settings.hpp"
#include <stdexcept>

Settings::Settings() {
  if (!texture.loadFromFile("../assets/sprites/blacknwhite.png")) {
    throw std::runtime_error("Failed to load texture");
  }
}

const sf::Texture &Settings::getTexture() const { return texture; }

Settings *Settings::getInstance() {
  static Settings instance;
  return &instance;
}
