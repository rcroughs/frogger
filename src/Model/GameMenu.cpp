#include "GameMenu.h"
#include "../Components/Buttons/MenuButton.h"
#include "../Components/Buttons/QuitButton.h"

GameMenu::GameMenu(int x, int y, Driver *driver)
    : _x{x}, _y{y}, _driver{driver}, _isOpen{false} {
  _image = std::make_shared<Fl_PNG_Image>("res/pause.png");
  _buttons.push_back(std::make_shared<MenuButton>(250, 275, driver));
  _buttons.push_back(std::make_shared<QuitButton>(250, 400));
}

GameMenu::~GameMenu() {}

int GameMenu::getX() const { return _x; }

int GameMenu::getY() const { return _y; }

std::vector<std::shared_ptr<Button>> GameMenu::getButtons() const {
  return _buttons;
}

std::shared_ptr<Fl_PNG_Image> GameMenu::getImage() const { return _image; }

bool GameMenu::isOpen() const { return _isOpen; }

void GameMenu::triggerMenu() { _isOpen = !_isOpen; } 