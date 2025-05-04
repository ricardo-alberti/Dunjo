#include "View/View.hpp"
#include <SFML/Graphics/View.hpp>

View::View(int _x, int _y, const std::string &title)
    : x(_x), y(_y), window(sf::VideoMode(sf::Vector2u(x, y)), title),
      viewText(
          sf::FloatRect(sf::Vector2f(0, 0),
                        sf::Vector2f(window.getSize().x, window.getSize().y))),
      view(
          sf::FloatRect(sf::Vector2f(0, 0),
                        sf::Vector2f(window.getSize().x, window.getSize().y))) {
  view.zoom(0.2f);
  window.setView(view);
}

void View::clear() { window.clear(); }
void View::display() { window.display(); }
bool View::isOpen() const { return window.isOpen(); }
sf::RenderWindow &View::getWindow() { return window; }
sf::View &View::getView() { return view; }
sf::View &View::getViewText() { return viewText; }
