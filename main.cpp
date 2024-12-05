#include <SFML/Graphics.hpp>

#include "mybutton.h"

#define CALCULATOR_BUTTON_SIZE 150.f

int main() {
  sf::RenderWindow window(sf::VideoMode(600, 800), "My window");
  myButton button1 =
      createButton(0, 0, "1", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);

  // run the program as long as the window is open
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    window.draw(button1.GetSquare());
    window.draw(button1.GetText());
    window.display();
  }
  return 0;
}
