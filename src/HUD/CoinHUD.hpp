#pragma once

#include "Entities/Player.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class CoinHUD {
private:
  sf::Font font;
  sf::Text counter;
  Player &player;

public:
  CoinHUD(Player &player)
      : player(player), font("../assets/fonts/04B_03.TTF"), counter(font) {
    this->player = player;
    counter.setString(std::to_string(player.score));
    counter.setFillColor(sf::Color::Cyan);
    counter.setCharacterSize(30);
    counter.setPosition({(int)20, (int)10});
  }

  const void update() { counter.setString(std::to_string(player.score)); };
  const sf::Text &getText() const { return counter; };
};
