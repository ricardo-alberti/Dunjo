#include "World.hpp"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>

World::World(View &_view, Player &_player, LevelController &_levelController)
    : view(_view), player(_player), levelController(_levelController) {
  collisionMediator = std::make_unique<CollisionMediator>();
}

void World::display() {
  LevelController::getInstance()->goNextLevel(player);

  sf::Clock clock;

  sf::Music music;
  music.openFromFile("../assets/music/nice_music.mp3");
  music.setLoop(true);
  // music.play();

  while (view.isOpen()) {
    deltaTime = clock.restart().asSeconds();

    sf::Event event;
    while (view.getWindow().pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        view.getWindow().close();
    }

    view.clear();

    collisionMediator->checkCollisions(
        player, LevelController::getInstance()->getCurrentLevel()->getTiles());

    LevelController::getInstance()->getCurrentLevel()->Update(deltaTime);
    LevelController::getInstance()->getCurrentLevel()->draw(view.getWindow());

    view.getView().setCenter(132, 100);
    view.getWindow().setView(view.getView());

    // player.getHitBoxSprite().drawHitBox(view.getWindow());
    view.getWindow().draw(player.getHitBoxSprite());
    player.Update(deltaTime);

    view.display();
  }
}
