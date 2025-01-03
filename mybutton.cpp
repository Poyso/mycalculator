#include "mybutton.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

myButton createButton(const int pos_x, const int pos_y, const char *text,
                      sf::Color shapeColor, sf::Color textColor,
                      const float width, const float height, int offset_x,
                      int offset_y) {
  sf::Text text_object;
  sf::RectangleShape rectangle;
  sf::Font font;
  myButton new_button(font, text_object, rectangle);
  new_button.SetFont("JetBrainsMono-Regular.ttf");
  new_button.SetText(text);
  new_button.SetSize(width, height);
  new_button.SetPosition(pos_x, pos_y, offset_x, offset_y);
  new_button.SetColor(shapeColor, textColor);
  return new_button;
}

float Sum(std::string text) {
  float sum;
  std::string firstadding, secondadding;
  for (int i = 0; i < text.find("+"); ++i) {
    firstadding += text[i];
  }

  for (int i = text.find("+") + 1; i < text.length(); ++i) {
    secondadding += text[i];
  }
  float firstNumber = std::stof(firstadding);
  float secondNumber = std::stof(secondadding);
  sum = firstNumber + secondNumber;
  int sum_int;

  return sum;
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
        std::string old_text = display->GetString();
        std::string new_string = b.GetString();
        if (new_string == "C") {
          display->Clear();
        } else if (new_string == "BS") {
          old_text.pop_back();
          if (old_text.length() == 0) {
            display->SetText("0");
          } else {
            display->SetText(old_text);
          }
        } else if (new_string == ".") {
          int dotFound = 0;
          if (old_text.find(".") < old_text.length())
            ++dotFound;
          if (dotFound != 1) {
            std::string text_combined = old_text + new_string;
            display->SetText(text_combined);
          }

        } else if (new_string == "+") {
          if (old_text[old_text.length() - 1] != '+') {
            if (old_text.find("+") < old_text.length()) {
              std::stringstream x;
              if (Sum(old_text) == ceil(Sum(old_text)))
                x << std::setprecision(0) << std::fixed << Sum(old_text);
              else
                x << std::setprecision(2) << std::fixed << Sum(old_text);
              display->Clear();
              old_text = x.str();
            }
            std::string text_combined = old_text + new_string;
            display->SetText(text_combined);
          }

        } else {
          if (old_text == "0")
            old_text.pop_back();

          std::string text_combined = old_text + new_string;
          display->SetText(text_combined);
        }
        *start_time = current_time + 0.1;
      }
    }
  }
}
