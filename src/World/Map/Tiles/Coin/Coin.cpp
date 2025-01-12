#include "Coin.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

Coin::Coin(int _x, int _y, sf::Sprite _sprite)
    : AnimatedTile(_x, _y,
                   std::make_shared<HitBoxSprite>(_sprite, x, y, 6.0f, 8.0f,
                                                  sf::Vector2f(3, 4))) {
  collectable = true;
  animation = std::make_unique<Animation>(this->hitBoxSprite, 0, 60, 0.2f, 5);
}

Coin::~Coin() = default;

void Coin::Update(float deltaTime) { animation->update(deltaTime); }

const void Coin::handleCollision() { this->hitBoxSprite->move(0, -10000); }
