#include "EditorButton.h"
#include "../../Driver.h"

EditorButton::EditorButton(int x, int y, Driver *driver)
    : _driver{driver}, _x{x}, _y{y} {
  _image = new Fl_PNG_Image("res/editor.png");
}

EditorButton::~EditorButton() { delete _image; }

Fl_PNG_Image *EditorButton::getImage() const { return _image; };

int EditorButton::getX() const { return _x; }

int EditorButton::getY() const { return _y; }

bool EditorButton::isDisplayed() const { return false; }

bool EditorButton::canMove() const { return false; }

bool EditorButton::isMoving() const { return false; }

bool EditorButton::contains(int x, int y) const {
  if (this->_x < x && x < this->_x + 200 && y < this->_y + 100 && this->_y < y)
    return true;
  return false;
}

void EditorButton::onClick() { _driver->launchEditor(); }

void EditorButton::resetPosition() { return; }

void EditorButton::changeMovingState() { return; }

void EditorButton::changePosition(int loc_x, int loc_y) {
  _x = loc_x;
  _y = loc_y;
}

void EditorButton::changeState() { return; }
