#include "SideWalkButton.h"
#include "../../Driver.h"
#include "iostream"
#include <memory>

SideWalkButton::SideWalkButton(int x, int y, Driver *driver)
    : x{x}, y{y}, driver{driver} {
  image = new Fl_PNG_Image("res/sidewalk_button.png");
}

bool SideWalkButton::contains(int x, int y) {
  if (x > getX() - 5 && x < (getX() + 46 + 5) && y > getY() - 5 &&
      y < getY() + 46 + 5)
    return true;
  return false;
}

void SideWalkButton::onClick() {
  if (driver->getEditor()->getCurrentRow() >= 0 &&
      driver->getEditor()->getCurrentRow() <= 12) {
    driver->getEditor()->setColor(new Fl_Color(FL_BLACK));
    driver->getEditor()->addEnvironment(driver->getEditor()->getCurrentRow(),
                                        2);
    driver->getEditor()->triggerEnvironmentButton();
  }
}
