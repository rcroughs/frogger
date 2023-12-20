#include "PropButton.h"
#include "../../Driver.h"

PropButton::PropButton(int x, int y, Driver *driver, short id)
    : x{x}, y{y}, driver{driver}, id{id} {
  if (id == 0) {
    image = new Fl_PNG_Image("res/log_button.png");
  } else { // id = 1;
    image = new Fl_PNG_Image("res/turtle_button.png");
  }
}

bool PropButton::contains(int x, int y) {
  if (x > getX() && x < (getX() + 46) && y > getY() && y < getY() + 50)
    return true;
  return false;
}

void PropButton::onClick() {}
