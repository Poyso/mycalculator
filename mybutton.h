#include <SFML/Graphics.hpp>

#define CHARACTER_SIZE 35
#define CENTER_OFFSET_X_TEXT 25.f
#define CENTER_OFFSET_Y_TEXT 15.f

class myButton {
public:
  myButton(sf::Font font, sf::Text text, sf::RectangleShape rectangle) {
    thisFont = font;
    thisText = text;
    thisRectangle = rectangle;
  }
  void SetFont(const char *font) {
    thisFont.loadFromFile(font);
    thisText.setFont(thisFont);
  }
  void SetSize(float h, float w) {
    thisRectangle.setSize(sf::Vector2f(h, w));
    thisText.setCharacterSize(CHARACTER_SIZE);
  }
  void SetText(const char *string) { thisText.setString(string); }
  void SetPosition(float x, float y) {
    thisRectangle.setPosition(x, y);
    thisText.setPosition(x + CENTER_OFFSET_X_TEXT, y + CENTER_OFFSET_Y_TEXT);
  }
  void SetColor(sf::Color squareColor, sf::Color textColor) {
    thisRectangle.setFillColor(squareColor);
    thisText.setFillColor(textColor);
  }
  sf::Text GetText() { return thisText; }
  sf::RectangleShape GetSquare() { return thisRectangle; }

private:
  sf::Text thisText;
  sf::RectangleShape thisRectangle;
  sf::Font thisFont;
};

#ifndef MYHEADER_H
#define MYHEADER_H
myButton createButton(const int pos_x, const int pos_y, const char *text,
                      sf::Color shapeColor, sf::Color textColor,
                      const float width, const float height);

#endif
