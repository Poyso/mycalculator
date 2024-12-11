#include "mybutton.h"
#include <SFML/Graphics/RenderWindow.hpp>

myButton createButton(const int pos_x, const int pos_y, const char *text,
                      sf::Color shapeColor, sf::Color textColor,
                      const float width, const float height) {
  sf::Text text_object;
  sf::RectangleShape rectangle;
  sf::Font font;
  myButton new_button(font, text_object, rectangle);
  new_button.SetFont("JetBrainsMono-Regular.ttf");
  new_button.SetText(text);
  new_button.SetSize(width, height);
  new_button.SetPosition(pos_x, pos_y);
  new_button.SetColor(shapeColor, textColor);
  return new_button;
}
void EventOnClick(myButton b, sf::RenderWindow *window) {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    // transform the mouse position from window coordinates to world
    // coordinates
    sf::Vector2f mouse =
        window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    // retrieve the bounding box of the sprite
    sf::FloatRect bounds = b.GetSquare().getGlobalBounds();

    // hit test
    if (bounds.contains(mouse)) {
      // TODO: insert the event when button is pressed
    }
  }
}
