#include "mybutton.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

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
void EventOnClick(myButton b, sf::RenderWindow *window, myDisplay *display,
                  float current_time, float *start_time) {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    // transform the mouse position from window coordinates to world
    // coordinates
    sf::Vector2f mouse =
        window->mapPixelToCoords(sf::Mouse::getPosition(*window));

    // retrieve the bounding box of the sprite
    sf::FloatRect bounds = b.GetSquare().getGlobalBounds();

    // hit test
    if (current_time > *start_time) {
      if (bounds.contains(mouse)) {
        // TODO: insert the event when button is pressed
        std::string new_string = b.GetString();
        if (new_string == "BS") {
          display->Clear();
        } else {
          std::string old_text = display->GetString();
          std::string text_combined = old_text + new_string;
          display->SetText(text_combined);
        }
        *start_time = current_time + 0.3;
      }
    }
  }
}
