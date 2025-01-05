#include "View.hpp"
#include <SFML/Graphics/View.hpp>

View::View(int _x, int _y, const std::string &title)
    : x(_x), y(_y), window(sf::VideoMode(x, y), title),
      view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)) {
  view.zoom(0.2f);
  window.setView(view);
}

void View::clear() { window.clear(); }
void View::display() { window.display(); }
bool View::isOpen() const { return window.isOpen(); }
sf::RenderWindow &View::getWindow() { return window; }
sf::View &View::getView() { return view; }
