#pragma once

#include <SFML/Graphics/Texture.hpp>

class Settings {
private:
  sf::Texture texture;
  static Settings *Instance;
  Settings();

public:
  const sf::Texture &getTexture() const;
  static Settings *getInstance();
};
