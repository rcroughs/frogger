#include "MenuButton.h"

MenuButton::MenuButton(int x, int y, Driver *driver)
    : _driver{driver}, _x{x}, _y{y} {
  _image = new Fl_PNG_Image("res/menu.png");
}

MenuButton::~MenuButton() { delete _image; }

Fl_PNG_Image *MenuButton::getImage() const { return _image; };

int MenuButton::getX() const { return _x; }

int MenuButton::getY() const { return _y; }

bool MenuButton::isDisplayed() const { return false; }

bool MenuButton::canMove() const { return false; }

bool MenuButton::isMoving() const { return false; }

bool MenuButton::contains(int x, int y) const {
  if (this->_x < x && x < this->_x + 200 && y < this->_y + 100 && this->_y < y)
    return true;
  return false;
}

void MenuButton::onClick() { _driver->showMenu(); }

void MenuButton::resetPosition() { return; }

void MenuButton::changeMovingState() { return; }

void MenuButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void MenuButton::changeState() { return; }
