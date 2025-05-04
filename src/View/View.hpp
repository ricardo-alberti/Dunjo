#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/View.hpp>

class View {
private:
  int x;
  int y;
  sf::RenderWindow window;
  sf::View view;
  sf::View viewText;

public:
  View(int _x = 1366, int _y = 768, const std::string &title = "Dunjo");
  void clear();
  void display();
  bool isOpen() const;
  sf::RenderWindow &getWindow();
  sf::View &getView();
  sf::View &getViewText();
};
