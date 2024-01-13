#include "SpeedButton.h"
#include "../../Driver.h"

SpeedButton::SpeedButton(int x, int y, Driver *driver, short id)
    : _driver{driver}, _x{x}, _y{y}, _id{id} {
  if (id == 0) {
    _image = new Fl_PNG_Image("res/speed_1.png");
  } else if (id == 1) {
    _image = new Fl_PNG_Image("res/speed_2.png");
  } else { // id = 2;
    _image = new Fl_PNG_Image("res/speed_3.png");
  }
}

SpeedButton::~SpeedButton() { delete _image; }

Fl_PNG_Image *SpeedButton::getImage() const { return _image; };

int SpeedButton::getX() const { return _x; }

int SpeedButton::getY() const { return _y; }

short SpeedButton::getId() const { return _id; }

bool SpeedButton::isDisplayed() const { return _displayed; }

bool SpeedButton::canMove() const { return false; }

bool SpeedButton::isMoving() const { return false; }

bool SpeedButton::contains(int x, int y) const {
  if (x > getX() && x < (getX() + 46) && y > getY() && y < getY() + 50)
    return true;
  return false;
}

void SpeedButton::onClick() {
  // Va modifier les paramètres pour les deux environnements
  // Une fois qu'un environnements est placé, tous ces paramètres sont reset
  switch (getId()) {
  case 0:
    _driver->getEditor()->modifyWaterFlow(0.5);
    _driver->getEditor()->modifyRoadSpeedLimit(1);
    break;
  case 1:
    _driver->getEditor()->modifyWaterFlow(1);
    _driver->getEditor()->modifyRoadSpeedLimit(1.5);
    break;
  case 2:
    _driver->getEditor()->modifyWaterFlow(1.5);
    _driver->getEditor()->modifyRoadSpeedLimit(2.5);
  }
  // Water or Road.
  short currentEnviNumber = _driver->getEditor()->getEnviNumber();
  _driver->getEditor()->addEnvironment(_driver->getEditor()->getCurrentRow(),1);
  if (currentEnviNumber == _driver->getEditor()->getEnviNumber()) {
      _driver->getEditor()->addEnvironment(_driver->getEditor()->getCurrentRow(),2);
  }
  _driver->getEditor()->triggerSpeedButtons();
}
void SpeedButton::resetPosition() { return; }

void SpeedButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void SpeedButton::changeMovingState() { return; }

void SpeedButton::changeState() { _displayed = !_displayed; }