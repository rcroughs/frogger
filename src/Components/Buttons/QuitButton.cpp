#include "QuitButton.h"

QuitButton::QuitButton(int x, int y) : _x{x}, _y{y} {
  _image = new Fl_PNG_Image("res/quit.png");
}

QuitButton::~QuitButton() { delete _image; }

Fl_PNG_Image *QuitButton::getImage() const { return _image; };

int QuitButton::getX() const { return _x; }

int QuitButton::getY() const { return _y; }

bool QuitButton::isDisplayed() const { return false; }

bool QuitButton::canMove() const { return false; }

bool QuitButton::isMoving() const { return false; }

bool QuitButton::contains(int x, int y) const {
  if (this->_x < x && x < this->_x + 200 && y < this->_y + 100 && this->_y < y)
    return true;
  return false;
}

void QuitButton::onClick() { exit(1); }

void QuitButton::resetPosition() { return; }

void QuitButton::changeMovingState() { return; }

void QuitButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void QuitButton::changeState() { return; }