#include "WaterButton.h"
#include "../../Driver.h"
#include "iostream"
#include <memory>

WaterButton::WaterButton(int x, int y, Driver* driver)
    : x{x}, y{y}, driver{driver} {
  image = new Fl_PNG_Image("res/water_button.png");
}

bool WaterButton::contains(int x, int y) {
  if (x > getX() - 5 && x < (getX() + 46 + 5) && y > getY() - 5 &&
      y < getY() + 46 + 5)
    return true;
  return false;
}

void WaterButton::showConfigurationButtons() {
  // Enable the configuration buttons to display at the right height
  std::vector<Button *> buttons = driver->getEditor()->getMenu()->getButtons();
  for (int i = 3; i < 8; i++) {
    buttons.at(i)->changeState();
    int height = driver->getEditor()->getWindowHeight();
    buttons.at(i)->changePosition(
        buttons.at(i)->getX(),
        (height - (height / 13.0f)) -
            (driver->getEditor()->getCurrentRow() * (height / 13.0)));
  }
}

void WaterButton::onClick() {
  if (driver->getEditor()->getCurrentRow() >= 0 &&
      driver->getEditor()->getCurrentRow() <= 12) {
    driver->getEditor()->setColor(new Fl_Color(FL_BLUE));
    driver->getEditor()->addEnvironment(driver->getEditor()->getCurrentRow(),
                                        2);
    showConfigurationButtons();
  }
}
