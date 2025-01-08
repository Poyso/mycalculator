#include "mybutton.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

sf::String minus = L"—";

myButton createButton(const int pos_x, const int pos_y, const sf::String text,
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

int checkLastChar(sf::String text, std::string mode) {
  if (mode == "equal") {
    if (text[text.getSize() - 1] == '+' || text[text.getSize() - 1] == minus ||
        text[text.getSize() - 1] == '*' || text[text.getSize() - 1] == '/') {
      return 1;
    } else
      return 0;
  } else if (mode == "nequal") {
    if (text[text.getSize() - 1] != '+' && text[text.getSize() - 1] != minus &&
        text[text.getSize() - 1] != '*' && text[text.getSize() - 1] != '/') {
      return 1;
    } else
      return 0;
  }
  return -1;
}

int checkOperations(sf::String text) {
  if (text.find("+") < text.getSize() || text.find(minus) < text.getSize() ||
      text.find("*") < text.getSize() || text.find("/") < text.getSize())
    return 1;
  else
    return 0;
}
sf::String push_start(sf::String text, int pos) {
  if (text[pos] != '-') {
    text.insert(pos, '-');
  } else {
    for (int i = pos; i < text.getSize(); ++i) {
      text[i] = text[i + 1];
    }
    text.erase(text.getSize() - 1);
  }
  return text;
}

float Sum(sf::String text) {
  float sum;
  std::string firstadding, secondadding;
  for (int i = 0; i < text.find("+"); ++i) {
    firstadding += text[i];
  }

  for (int i = text.find("+") + 1; i < text.getSize(); ++i) {
    secondadding += text[i];
  }
  float firstNumber = std::stof(firstadding);
  float secondNumber = std::stof(secondadding);
  sum = firstNumber + secondNumber;

  return sum;
}
float Sub(sf::String text) {
  float sub;
  std::string firstadding, secondadding;
  for (int i = 0; i < text.find(minus); ++i) {
    firstadding += text[i];
  }

  for (int i = text.find(minus) + 1; i < text.getSize(); ++i) {
    secondadding += text[i];
  }
  float firstNumber = std::stof(firstadding);
  float secondNumber = std::stof(secondadding);
  sub = firstNumber - secondNumber;

  return sub;
}
float Mul(sf::String text) {
  float mul;
  std::string firstadding, secondadding;
  for (int i = 0; i < text.find("*"); ++i) {
    firstadding += text[i];
  }

  for (int i = text.find("*") + 1; i < text.getSize(); ++i) {
    secondadding += text[i];
  }
  float firstNumber = std::stof(firstadding);
  float secondNumber = std::stof(secondadding);
  mul = firstNumber * secondNumber;

  return mul;
}
float Div(sf::String text) {
  float div;
  std::string firstadding, secondadding;
  for (int i = 0; i < text.find("/"); ++i) {
    firstadding += text[i];
  }

  for (int i = text.find("/") + 1; i < text.getSize(); ++i) {
    secondadding += text[i];
  }
  float firstNumber = std::stof(firstadding);
  float secondNumber = std::stof(secondadding);
  div = firstNumber / secondNumber;

  return div;
}
float Operation(sf::String text) {
  int t = 0;
  float result;
  sf::String symbols[] = {'+', minus, '*', '/'};
  for (int i = 0; i < 4; ++i) {
    ++t;
    if (text.find(symbols[i]) < text.getSize())
      break;
  }
  switch (t) {
  case 1:
    result = Sum(text);
    break;
  case 2:
    result = Sub(text);
    break;
  case 3:
    result = Mul(text);
    break;
  case 4:
    result = Div(text);
    break;
  }
  return result;
}
int returnPosSymbol(sf::String text) {
  if (text.find("+") < text.getSize())
    return text.find("+");
  else if (text.find(minus) < text.getSize())
    return text.find(minus);
  else if (text.find("*") < text.getSize())
    return text.find("*");
  else if (text.find("/") < text.getSize())
    return text.find("/");
  return 0;
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
        sf::String old_text = display->GetString();
        sf::String new_string = b.GetString();
        if (new_string == "C") {
          display->Clear();
        } else if (new_string == "<-") {
          old_text.erase(old_text.getSize() - 1);
          if (old_text.getSize() == 0) {
            display->SetText("0");
          } else {
            display->SetText(old_text);
          }
        } else if (new_string == ".") {
          int dotFoundBeforeOperation = 0, dotFoundAfterOperation = 0;
          for (int i = 0; i < returnPosSymbol(old_text); ++i) {
            if (old_text[i] == '.')
              ++dotFoundBeforeOperation;
          }
          for (int i = returnPosSymbol(old_text); i < old_text.getSize(); ++i) {
            if (old_text[i] == '.')
              ++dotFoundAfterOperation;
          }
          if (dotFoundBeforeOperation < 1 && !(checkOperations(old_text))) {
            sf::String text_combined = old_text + new_string;
            display->SetText(text_combined);
          } else if (dotFoundAfterOperation < 1) {
            if (checkLastChar(old_text, "equal"))
              new_string = "0.";
            sf::String text_combined = old_text + new_string;
            display->SetText(text_combined);
          }
        } else if (new_string == "+") {
          if (checkOperations(old_text) && checkLastChar(old_text, "nequal")) {
            std::stringstream x;
            if (Operation(old_text) == ceil(Operation(old_text)))
              x << std::setprecision(0) << std::fixed << Operation(old_text);
            else
              x << std::setprecision(2) << std::fixed << Operation(old_text);
            display->Clear();
            old_text = x.str();
          }
          sf::String text_combined = old_text;
          if (checkLastChar(old_text, "equal"))
            text_combined.erase(text_combined.getSize() - 1);
          text_combined += new_string;
          display->SetText(text_combined);
        } else if (new_string == minus) {
          if (checkOperations(old_text) && checkLastChar(old_text, "nequal")) {
            std::stringstream x;
            if (Operation(old_text) == ceil(Operation(old_text)))
              x << std::setprecision(0) << std::fixed << Operation(old_text);
            else
              x << std::setprecision(2) << std::fixed << Operation(old_text);
            display->Clear();
            old_text = x.str();
          }
          sf::String text_combined = old_text;
          if (checkLastChar(old_text, "equal"))
            text_combined.erase(text_combined.getSize() - 1);
          text_combined += new_string;
          display->SetText(text_combined);

        } else if (new_string == "*") {
          if (checkOperations(old_text) && checkLastChar(old_text, "nequal")) {
            std::stringstream x;
            if (Operation(old_text) == ceil(Operation(old_text)))
              x << std::setprecision(0) << std::fixed << Operation(old_text);
            else
              x << std::setprecision(2) << std::fixed << Operation(old_text);
            display->Clear();
            old_text = x.str();
          }
          sf::String text_combined = old_text;
          if (checkLastChar(old_text, "equal"))
            text_combined.erase(text_combined.getSize() - 1);
          text_combined += new_string;
          display->SetText(text_combined);

        } else if (new_string == "/") {
          if (checkOperations(old_text) && checkLastChar(old_text, "nequal")) {
            std::stringstream x;
            if (Operation(old_text) == ceil(Operation(old_text)))
              x << std::setprecision(0) << std::fixed << Operation(old_text);
            else
              x << std::setprecision(2) << std::fixed << Operation(old_text);
            display->Clear();
            old_text = x.str();
          }
          sf::String text_combined = old_text;
          if (checkLastChar(old_text, "equal"))
            text_combined.erase(text_combined.getSize() - 1);
          text_combined += new_string;
          display->SetText(text_combined);

        } else if (new_string == "=") {
          if (checkOperations(old_text) && checkLastChar(old_text, "nequal")) {
            std::cout << "check" << std::endl;
            std::stringstream x;
            if (Operation(old_text) == ceil(Operation(old_text)))
              x << std::setprecision(0) << std::fixed << Operation(old_text);
            else
              x << std::setprecision(2) << std::fixed << Operation(old_text);
            display->Clear();
            old_text = x.str();
            display->SetText(old_text);
          }

        } else if (new_string == "+/-") {
          sf::String text = old_text;
          if (checkOperations(old_text) && old_text != "0") {
            text = push_start(text, returnPosSymbol(old_text) + 1);

          } else if ((old_text.find("+") > old_text.getSize() ||
                      old_text.find(minus) > old_text.getSize() ||
                      old_text.find("*") > old_text.getSize() ||
                      old_text.find("/") > old_text.getSize()) &&
                     old_text != "0") {
            text = push_start(old_text, 0);
          }
          display->SetText(text);
        } else if (new_string == "CE") {
          int n = old_text.getSize() - 1;
          while (returnPosSymbol(old_text) + 1 <= n) {
            old_text.erase(n);
            --n;
          }
          display->SetText(old_text);
        } else {
          if (old_text == "0") {
            old_text.erase(old_text.getSize() - 1);
          }

          sf::String text_combined = old_text + new_string;
          display->SetText(text_combined);
        }
        *start_time = current_time + 0.1;
      }
    }
  }
}
