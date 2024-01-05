#include "WinningMenu.h"
#include "Buttons/MenuButton.h"
#include "Buttons/PlayAgainButton.h"

WinningMenu::WinningMenu(Driver *driver) {
  _image = new Fl_PNG_Image("res/victory.png");
  _buttons.push_back(std::make_shared<PlayAgainButton>(250, 520, driver));
  _buttons.push_back(std::make_shared<MenuButton>(250, 400, driver));
}

WinningMenu::~WinningMenu() {
  delete _image;
}

Fl_PNG_Image *WinningMenu::getImage() const { return _image; }

std::vector<std::shared_ptr<Button>> WinningMenu::getButtons() const {
  return _buttons;
}