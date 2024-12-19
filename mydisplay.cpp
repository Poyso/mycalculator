#include "mydisplay.h"

#define MY_FONT "JetBrainsMono-Regular.ttf"

myDisplay createDisplay() {
  sf::Text test;
  sf::Font font;
  myDisplay display(test, font);
  display.SetFont(MY_FONT);
  display.SetText("0");
  display.SetPos(0, 20);
  return display;
}
