#include "ProfileButton.h"
#include <memory>

ProfileButton::ProfileButton(int x, int y, MenuComponents* MenuComponents) : _x(x), _y(y), menuComponents(MenuComponents) {
  image = new Fl_PNG_Image("res/profile.png");
}

ProfileButton::~ProfileButton() { delete image; }

Fl_PNG_Image *ProfileButton::getImage() { return image; }

int ProfileButton::getX() { return _x; }

int ProfileButton::getY() { return _y; }

bool ProfileButton::contains(int x, int y) {
  if (x >= _x && x <= _x + 50 && y >= _y && y <= _y + 50)
    return true;
  return false;
}

bool ProfileButton::canMove() { return false; }

void ProfileButton::onClick() {
    menuComponents->openProfile();
}


void ProfileButton::resetPosition() {}

bool ProfileButton::isDisplayed() { return true; }

bool ProfileButton::isMoving() { return false; }

void ProfileButton::changeMovingState() {}

void ProfileButton::changeState() {}

void ProfileButton::changePosition(int loc_x, int loc_y) {}
