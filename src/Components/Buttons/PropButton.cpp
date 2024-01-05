#include "PropButton.h"
#include "../../Driver.h"

PropButton::PropButton(int x, int y, Driver *driver, short id)
    : _driver{driver}, _x{x}, _y{y}, _id{id} {
  if (id == 0) {
    _image = new Fl_PNG_Image("res/log_button.png");
  } else { // id = 1;
    _image = new Fl_PNG_Image("res/turtle_button.png");
  }
}

PropButton::~PropButton() { delete _image; }

Fl_PNG_Image *PropButton::getImage() const { return _image; };

int PropButton::getX() const { return _x; }

int PropButton::getY() const { return _y; }

bool PropButton::isDisplayed() const { return _displayed; }

bool PropButton::canMove() const { return false; }

bool PropButton::isMoving() const { return false; }

bool PropButton::contains(int x, int y) const {
  if (x > getX() && x < (getX() + 46) && y > getY() && y < getY() + 50)
    return true;
  return false;
}

void PropButton::onClick() { return; }

void PropButton::resetPosition() { return; }

void PropButton::changeMovingState() { return; }

void PropButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void PropButton::changeState() { _displayed = !_displayed; }
