#include "PlayAgainButton.h"


PlayAgainButton::PlayAgainButton(int x, int y, Driver *driver, std::string filePath)
    : _driver{driver}, _x{x}, _y{y} , _filePath{filePath} {
  _image = new Fl_PNG_Image("res/playagain.png");
}

PlayAgainButton::~PlayAgainButton() { delete _image; }

Fl_PNG_Image *PlayAgainButton::getImage() const { return _image; };

int PlayAgainButton::getX() const { return _x; }

int PlayAgainButton::getY() const { return _y; }

bool PlayAgainButton::isDisplayed() const { return false; }

bool PlayAgainButton::canMove() const { return false; }

bool PlayAgainButton::isMoving() const { return false; }

bool PlayAgainButton::contains(int x, int y) const {
  if (this->_x < x && x < this->_x + 200 && y < this->_y + 100 && this->_y < y)
    return true;
  return false;
}

void PlayAgainButton::onClick() { _driver->LaunchGameFromFile(_filePath); }

void PlayAgainButton::resetPosition() { return; }

void PlayAgainButton::changeMovingState() { return; }

void PlayAgainButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void PlayAgainButton::changeState() { return; }