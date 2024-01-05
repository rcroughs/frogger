#include "PlayButton.h"
#include "../../Driver.h"

PlayButton::PlayButton(int x, int y, Driver *driver)
    : _driver{driver}, _x{x}, _y{y} {
  _image = new Fl_PNG_Image("res/play.png");
}

PlayButton::~PlayButton() { delete _image; }

Fl_PNG_Image *PlayButton::getImage() const { return _image; };

int PlayButton::getX() const { return _x; }

int PlayButton::getY() const { return _y; }

bool PlayButton::isDisplayed() const { return false; }

bool PlayButton::canMove() const { return false; }

bool PlayButton::isMoving() const { return false; }

bool PlayButton::contains(int x, int y) const {
  if (this->_x < x && x < this->_x + 200 && y < this->_y + 100 && this->_y < y)
    return true;
  return false;
}

void PlayButton::onClick() { _driver->launchLevelSelection(); }

void PlayButton::resetPosition() { return; }

void PlayButton::changeMovingState() { return; }

void PlayButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void PlayButton::changeState() { return; }  