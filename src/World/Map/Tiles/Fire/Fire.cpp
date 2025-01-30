#include "Fire.hpp"
#include "../../../LevelController/LevelController.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <random>

Fire::Fire(int _x, int _y, sf::Sprite _sprite)
    : AnimatedTile(_x, _y,
                   std::make_shared<HitBoxSprite>(_sprite, x, y, 6.0f, 8.0f,
                                                  sf::Vector2f(3, 4))) {
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_real_distribution<float> distribution(0.52f, 1.0f);

  frameTime = distribution(generator);
}
Fire::~Fire() = default;

void Fire::Update(float _deltaTime) {
  timePassed += _deltaTime;

  hitBoxSprite->move(0, 0.0003);
  if (timePassed >= frameTime) {
    timePassed = 0;
    hitBoxSprite->setPosition(x, y);
  }
}

const void Fire::handleCollision(Player &player) {
  player.takeDamage();
  LevelController::getInstance()->reset(player);
}
