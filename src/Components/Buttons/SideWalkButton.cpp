#include "SideWalkButton.h"
#include "../../Driver.h"
#include <FL/Fl.H>

SideWalkButton::SideWalkButton(int x, int y, Driver *driver)
    : _driver{driver}, _x{x}, _y{y} {
  _image = new Fl_PNG_Image("res/sidewalk_button.png");
}

SideWalkButton::~SideWalkButton() { delete _image; }

Fl_PNG_Image *SideWalkButton::getImage() const { return _image; };

int SideWalkButton::getX() const { return _x; }

int SideWalkButton::getY() const { return _y; }

bool SideWalkButton::isDisplayed() const { return _displayed; }

bool SideWalkButton::canMove() const { return true; }

bool SideWalkButton::isMoving() const { return _moving; }

bool SideWalkButton::contains(int x, int y) const {
  if (x > getX() - 5 && x < (getX() + 46 + 5) && y > getY() - 5 &&
      y < getY() + 46 + 5)
    return true;
  return false;
}

void SideWalkButton::onClick() {
  if (_driver->getEditor()->getCurrentRow() >= 1 &&
      _driver->getEditor()->getCurrentRow() <= 11) {
    _driver->getEditor()->setColor(new Fl_Color(FL_BLACK));
    _driver->getEditor()->addEnvironment(_driver->getEditor()->getCurrentRow(),0);
    _driver->getEditor()->triggerEnvironmentButton();
  }
}

void SideWalkButton::resetPosition() {
  changePosition(2 * (700 / 3) + (700 / 3) / 2 - 23, 700);
}

void SideWalkButton::changeMovingState() { _moving = !_moving; }

void SideWalkButton::changeState() { _displayed = !_displayed; }

void SideWalkButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}