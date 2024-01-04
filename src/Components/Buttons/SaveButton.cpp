#include "SaveButton.h"
#include <memory>

SaveButton::SaveButton(int x, int y, Driver* driver, std::shared_ptr<TextInput> TextInput) : _x{x}, _y{y}, driver{driver}, _textInput{TextInput} {
    image = new Fl_PNG_Image("res/save.png");
}

SaveButton::~SaveButton() { delete image; }

Fl_PNG_Image *SaveButton::getImage() { return image; }

int SaveButton::getX() { return _x; }

int SaveButton::getY() { return _y; }

bool SaveButton::contains(int x, int y) {
    if (x >= _x && x <= _x + 250 && y >= _y && y <= _y + 100)
        return true;
    return false;
}

bool SaveButton::canMove() { return false; }

void SaveButton::onClick() {
    driver->saveNickname(_textInput->getInput());
}

void SaveButton::resetPosition() {}

bool SaveButton::isDisplayed() { return true; }

bool SaveButton::isMoving() { return false; }

void SaveButton::changeMovingState() {}

void SaveButton::changeState() {}

void SaveButton::changePosition(int loc_x, int loc_y) {}
