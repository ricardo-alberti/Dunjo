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
  HitBoxSprite(sf::Sprite &sprite, float x = 0, float y = 0, float width = 12,
               float height = 12, sf::Vector2f offset = {0, 0})
      : sf::Sprite(sprite),
        box(sf::Vector2f(x, y), sf::Vector2f(width, height)), offset(offset) {}

  void setPosition(float x, float y) {
    sf::Sprite::setPosition(sf::Vector2f(x, y));
    updateHitBox();
  }

  void setOrigin(float x, float y) {
    sf::Sprite::setOrigin(sf::Vector2f(x, y));
    sf::Vector2f position = getPosition();
    origin = {x, y};

    box = sf::FloatRect(position + offset - origin, box.size);
  }

  void move(float offsetX, float offsetY) {
    sf::Sprite::move(sf::Vector2f(offsetX, offsetY));
    updateHitBox();
  }

  void updateHitBox() {
    sf::Vector2f position = getPosition();
    box = sf::FloatRect(position + offset - origin, box.size);
  }

  bool intersects(const HitBoxSprite &other) const {
    return box.findIntersection(other.box).has_value();
  }

  const sf::FloatRect getRect() const { return box; }
  float getHeight() const { return box.size.y; }

  float getLeft() const { return getPosition().x; }

  void drawHitBox(sf::RenderWindow &window) const {
    sf::RectangleShape debugBox;
    debugBox.setPosition(box.position);
    debugBox.setSize(box.size);
    debugBox.setFillColor(sf::Color::Transparent);
    debugBox.setOutlineColor(sf::Color::Red);
    debugBox.setOutlineThickness(1);
    window.draw(debugBox);
  }
};
