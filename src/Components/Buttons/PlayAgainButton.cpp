#include "PlayAgainButton.h"


PlayAgainButton::PlayAgainButton(int x, int y, Driver *driver)
    : x{x}, y{y}, driver{driver} {
  image = new Fl_PNG_Image("res/playagain.png");
}

bool PlayAgainButton::contains(int x, int y) {
  if (this->x < x && x < this->x + 200 && y < this->y + 100 && this->y < y)
    return true;
  return false;
}

void PlayAgainButton::onClick() { driver->launchGame(); }