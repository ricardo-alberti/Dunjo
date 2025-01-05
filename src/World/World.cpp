#include "World.hpp"
#include "../Utils/CollisionManager/CollisionManager.hpp"
#include "../Map/Map.hpp"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>

World::World(View &_view, Player &_player) : view(_view), player(_player) {}

void World::display() {
  float deltaTime = 0.0f; // tempo acumulado entre frames
  Map map = Map();
  map.loadTiles();

  sf::Clock clock;

  sf::Music music;
  music.openFromFile("../assets/music/nice_music2.mp3");
  music.setLoop(true);
  music.play();

  while (view.isOpen()) {
    deltaTime = clock.restart().asSeconds();

    sf::Event event;
    while (view.getWindow().pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        view.getWindow().close();
    }

    view.clear();

    map.draw(view.getWindow());
    view.getWindow().draw(player.getSprite());
    //player.getSprite().drawHitBox(view.getWindow());

    player.Update(deltaTime);
    map.Update(deltaTime);
    CollisionManager::checkCollisions(player, map.getTiles());

    view.getView().setCenter(132, 100);
    view.getWindow().setView(view.getView());

    view.display();
  }
}
