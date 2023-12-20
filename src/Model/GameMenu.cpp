#include "GameMenu.h"
#include "../Components/Buttons/MenuButton.h"
#include "../Components/Buttons/QuitButton.h"

GameMenu::GameMenu(int x, int y, Driver* driver) : _x{x}, _y{y}, _driver{driver} {
  _image = std::make_shared<Fl_PNG_Image>("res/pause.png");
  _buttons.push_back(new MenuButton(250, 275, driver));
  _buttons.push_back(new QuitButton(250, 400));
}

GameMenu::~GameMenu() {
  for (auto &button : _buttons) {
    delete button;
  }
}