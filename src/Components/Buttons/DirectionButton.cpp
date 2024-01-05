#include "DirectionButton.h"
#include "../../Driver.h"

DirectionButton::DirectionButton(int x, int y, Driver *driver, short id)
    : _driver{driver}, _x{x}, _y{y}, _id{id} {
  if (id == 0) {
    _image = new Fl_PNG_Image("res/left.png");
  } else { // id = 1;
    _image = new Fl_PNG_Image("res/right.png");
  }
}

DirectionButton::~DirectionButton() { delete _image; }

Fl_PNG_Image *DirectionButton::getImage() const { return _image; };

int DirectionButton::getX() const { return _x; }

int DirectionButton::getY() const { return _y; }

bool DirectionButton::isDisplayed() const { return false; }

bool DirectionButton::canMove() const { return false; }

bool DirectionButton::isMoving() const { return false; }

bool DirectionButton::contains(int x, int y) const {
  if (x > getX() && x < (getX() + 46) && y > getY() && y < getY() + 50)
    return true;
  return false;
}

void DirectionButton::onClick() {
  changeState();
  if (getId() == 0) {
    _driver->getEditor()->modifyRoadCirculation('l');
  } else {
    _driver->getEditor()->modifyRoadCirculation('r');
  }
  _driver->getEditor()->addEnvironment(_driver->getEditor()->getCurrentRow(), 1);
}

void DirectionButton::resetPosition() { return; }

void DirectionButton::changeMovingState() { return; }

void DirectionButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void DirectionButton::changeState() { return; }

short DirectionButton::getId() const { return _id; }