#include "WaterButton.h"
#include "../../Driver.h"
#include "../../Model/GameEditor.h"
#include "../../Model/EditorMenu.h"

WaterButton::WaterButton(int x, int y, Driver* driver)
    : _driver{driver}, _x{x}, _y{y} {
  _image = new Fl_PNG_Image("res/water_button.png");
}

WaterButton::~WaterButton() { delete _image; }

Fl_PNG_Image *WaterButton::getImage() const { return _image; };

int WaterButton::getX() const { return _x; }

int WaterButton::getY() const { return _y; }

bool WaterButton::contains(int x, int y) const {
  if (x > getX() - 5 && x < (getX() + 46 + 5) && y > getY() - 5 &&
      y < getY() + 46 + 5)
    return true;
  return false;
}

bool WaterButton::isDisplayed() const { return _displayed; }

bool WaterButton::canMove() const { return true; }

bool WaterButton::isMoving() const { return _moving; }

void WaterButton::onClick() {
  if (_driver->getEditor()->getCurrentRow() >= 1 &&
      _driver->getEditor()->getCurrentRow() <= 11) {
    _driver->getEditor()->setColor(new Fl_Color(FL_BLUE));
    showConfigurationButtons();
    _driver->getEditor()->addEnvironment(_driver->getEditor()->getCurrentRow(),2);
    _driver->getEditor()->resetTimeOut();
  }
}

void WaterButton::resetPosition() { changePosition(((700 / 3) / 2) - 23, 700); }

void WaterButton::changeMovingState() { _moving = !_moving; }

void WaterButton::changeState() { _displayed = !_displayed; }

void WaterButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void WaterButton::showConfigurationButtons() {
  // Enables the configuration buttons to display at the right height
  std::vector<std::shared_ptr<Button>> buttons = _driver->getEditor()->getMenu()->getButtons();
  _driver->getEditor()->triggerSpeedButtons();
  _driver->getEditor()->triggerPropsButtons();
  for (int i = 3; i < 8; i++) {
    int height = _driver->getEditor()->getWindowHeight();
    buttons.at(i)->changePosition(
        buttons.at(i)->getX(),
        (height - (height / 13.0f)) -
            (_driver->getEditor()->getCurrentRow() * (height / 13.0) - ((height / 13.0) / 10)));
  }
}