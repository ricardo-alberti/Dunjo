#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class HitBoxSprite : public sf::Sprite {
private:
  sf::FloatRect box;
  sf::Vector2f origin;
  sf::Vector2f offset;

public:
  HitBoxSprite(sf::Sprite &sprite, float x, float y, float width = 12,
               float height = 12, sf::Vector2f offset = {0, 0})
      : sf::Sprite(sprite), box(x, y, width, height), offset(offset) {}

  void setPosition(float x, float y) {
    sf::Sprite::setPosition(x, y);
    updateHitBox();
  }

  void setOrigin(float x, float y) {
    sf::Sprite::setOrigin(x, y);
    sf::Vector2f position = getPosition();

    origin = {x, y};

    box.left = position.x - x + offset.x;
    box.top = position.y - y + offset.y;
  }

  void move(float offsetX, float offsetY) {
    sf::Sprite::move(offsetX, offsetY);
    updateHitBox();
  }

  void updateHitBox() {
    sf::Vector2f position = getPosition();
    box.left = position.x - origin.x + offset.x;
    box.top = position.y - origin.y + offset.y;
  }

  bool intersects(const HitBoxSprite &other) const {
    return box.intersects(other.box);
  }

  sf::FloatRect getRect() const { return box; }

  void drawHitBox(sf::RenderWindow &window) const {
    sf::RectangleShape debugBox;
    debugBox.setPosition(box.left, box.top);
    debugBox.setSize(sf::Vector2f(box.width, box.height));
    debugBox.setFillColor(sf::Color::Transparent);
    debugBox.setOutlineColor(sf::Color::Red);
    debugBox.setOutlineThickness(1);
    window.draw(debugBox);
  }
};
