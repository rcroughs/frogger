#include "PauseMenu.h"
#include "../Components/Buttons/MenuButton.h"
#include "../Components/Buttons/QuitButton.h"
#include "../Driver.h"

PauseMenu::PauseMenu(int x, int y, Driver *driver)
    : _x{x}, _y{y}, _driver{driver}, _isOpen{false} {
  _image = std::make_shared<Fl_PNG_Image>("res/pause.png");
  _buttons.push_back(std::make_shared<MenuButton>(250, 275, driver));
  _buttons.push_back(std::make_shared<QuitButton>(250, 400));
}

PauseMenu::~PauseMenu() {}

int PauseMenu::getX() const { return _x; }

int PauseMenu::getY() const { return _y; }

std::vector<std::shared_ptr<Button>> PauseMenu::getButtons() const {
  return _buttons;
}

std::shared_ptr<Fl_PNG_Image> PauseMenu::getImage() const { return _image; }

bool PauseMenu::isOpen() const { return _isOpen; }

void PauseMenu::triggerMenu() { _isOpen = !_isOpen; } 