#include <SFML/Graphics.hpp>

class myDisplay {
public:
  myDisplay(sf::Text txt, sf::Font font) {
    displayText = txt;
    displayFont = font;
    displayText.setFillColor(sf::Color::White);
    displayText.setCharacterSize(75);
  }
  void SetFont(const char *ttf) {
    displayFont.loadFromFile(ttf);
    displayText.setFont(displayFont);
  }
  void SetPos(float x, float y) { displayText.setPosition(x, y); }
  void SetText(std::string ch) { displayText.setString(ch); }
  std::string GetString() { return displayText.getString(); }
  sf::Text GetText() { return displayText; }
  void Clear() { displayText.setString(""); }

private:
  sf::Text displayText;
  sf::Font displayFont;
};

myDisplay createDisplay();
