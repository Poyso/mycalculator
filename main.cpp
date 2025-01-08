#include "mybutton.h"
#include <SFML/System/Clock.hpp>

#define CALCULATOR_BUTTON_SIZE 75.f
#define MY_FONT "JetBrainsMono-Regular.ttf"

int main() {
  sf::RenderWindow window(sf::VideoMode(325, 550), "My window");
  sf::String minus = L"—";
  myDisplay display = createDisplay();
  // 1st row startng from the bottom negative-0-.-=
  myButton buttonNegative = createButton(
      0, 470, "+/-", sf::Color::White, sf::Color::Black, CALCULATOR_BUTTON_SIZE,
      CALCULATOR_BUTTON_SIZE, -18, 0); // TODO: symbol for negative operation
  myButton button0 =
      createButton(85, 470, "0", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton buttonDot =
      createButton(170, 470, ".", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton buttonEq =
      createButton(255, 470, "=", sf::Color::Blue, sf::Color::White,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  // 2nd row starting from the bottom 1-2-3-+
  myButton button1 =
      createButton(0, 385, "1", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton button2 =
      createButton(85, 385, "2", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton button3 =
      createButton(170, 385, "3", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton buttonPlus =
      createButton(255, 385, "+", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  // 3rd starting from the bottom 4-5-6--
  myButton button4 =
      createButton(0, 300, "4", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton button5 =
      createButton(85, 300, "5", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton button6 =
      createButton(170, 300, "6", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton buttonMinus =
      createButton(255, 300, minus, sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  // 4th starting from the bottom 7-8-9-*
  myButton button7 =
      createButton(0, 215, "7", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton button8 =
      createButton(85, 215, "8", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton button9 =
      createButton(170, 215, "9", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton buttonMul =
      createButton(255, 215, "*", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  // 5th row starting from the bottom c-ce-backspace-/
  myButton buttonC =
      createButton(0, 130, "C", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  myButton buttonCE =
      createButton(85, 130, "CE", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE, -8, 0);
  // TODO: find an emoji for the button ce and possibly another button instead
  // of ce
  myButton buttonBS =
      createButton(170, 130, "<-", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE, -10, 0);
  // TODO: find a an emoji for back space
  myButton buttonDiv =
      createButton(255, 130, "/", sf::Color::White, sf::Color::Black,
                   CALCULATOR_BUTTON_SIZE, CALCULATOR_BUTTON_SIZE);
  sf::Clock clock;
  float startTime = 1;

  // run the program as long as the window is open
  while (window.isOpen()) {
    float currentTime = clock.getElapsedTime().asSeconds();
    // clock.restart();
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      // Event to make work numerical buttons
      EventOnClick(button0, &window, &display, currentTime, &startTime);
      EventOnClick(button1, &window, &display, currentTime, &startTime);
      EventOnClick(button2, &window, &display, currentTime, &startTime);
      EventOnClick(button3, &window, &display, currentTime, &startTime);
      EventOnClick(button4, &window, &display, currentTime, &startTime);
      EventOnClick(button5, &window, &display, currentTime, &startTime);
      EventOnClick(button6, &window, &display, currentTime, &startTime);
      EventOnClick(button7, &window, &display, currentTime, &startTime);
      EventOnClick(button8, &window, &display, currentTime, &startTime);
      EventOnClick(button9, &window, &display, currentTime, &startTime);
      EventOnClick(buttonDot, &window, &display, currentTime, &startTime);
      EventOnClick(buttonBS, &window, &display, currentTime, &startTime);
      EventOnClick(buttonC, &window, &display, currentTime, &startTime);
      EventOnClick(buttonPlus, &window, &display, currentTime, &startTime);
      EventOnClick(buttonMinus, &window, &display, currentTime, &startTime);
      EventOnClick(buttonMul, &window, &display, currentTime, &startTime);
      EventOnClick(buttonDiv, &window, &display, currentTime, &startTime);
      EventOnClick(buttonNegative, &window, &display, currentTime, &startTime);
      EventOnClick(buttonCE, &window, &display, currentTime, &startTime);
      EventOnClick(buttonEq, &window, &display, currentTime, &startTime);
    }
    window.clear();
    window.draw(display.GetText());
    // printing 1st row
    window.draw(buttonNegative.GetSquare());
    window.draw(buttonNegative.GetText());
    window.draw(button0.GetSquare());
    window.draw(button0.GetText());
    window.draw(buttonDot.GetSquare());
    window.draw(buttonDot.GetText());
    window.draw(buttonEq.GetSquare());
    window.draw(buttonEq.GetText());
    // printing 2nd row
    window.draw(button1.GetSquare());
    window.draw(button1.GetText());
    window.draw(button2.GetSquare());
    window.draw(button2.GetText());
    window.draw(button3.GetSquare());
    window.draw(button3.GetText());
    window.draw(buttonPlus.GetSquare());
    window.draw(buttonPlus.GetText());
    // printing 3rd row
    window.draw(button4.GetSquare());
    window.draw(button4.GetText());
    window.draw(button5.GetSquare());
    window.draw(button5.GetText());
    window.draw(button6.GetSquare());
    window.draw(button6.GetText());
    window.draw(buttonMinus.GetSquare());
    window.draw(buttonMinus.GetText());
    // printing 4th row
    window.draw(button7.GetSquare());
    window.draw(button7.GetText());
    window.draw(button8.GetSquare());
    window.draw(button8.GetText());
    window.draw(button9.GetSquare());
    window.draw(button9.GetText());
    window.draw(buttonMul.GetSquare());
    window.draw(buttonMul.GetText());
    // printing 5th row
    window.draw(buttonC.GetSquare());
    window.draw(buttonC.GetText());
    window.draw(buttonCE.GetSquare());
    window.draw(buttonCE.GetText());
    window.draw(buttonBS.GetSquare());
    window.draw(buttonBS.GetText());
    window.draw(buttonDiv.GetSquare());
    window.draw(buttonDiv.GetText());
    window.display();
  }
  return 0;
}
