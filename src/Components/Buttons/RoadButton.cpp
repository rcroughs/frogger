#include "RoadButton.h"
#include "../../Driver.h"
#include "../../Model/GameEditor.h"
#include "../../Model/EditorMenu.h"
#include <FL/Fl_PNG_Image.H>

RoadButton::RoadButton(int x, int y, Driver* driver) : _driver{driver}, _x{x}, _y{y} {
    _image = new Fl_PNG_Image("res/road_button.png");
}

RoadButton::~RoadButton() {
    delete _image;
}

Fl_PNG_Image* RoadButton::getImage() const {
    return _image;
}

int RoadButton::getX() const {
    return _x;
}

int RoadButton::getY() const {
    return _y;
}

bool RoadButton::isDisplayed() const {
    return _displayed;
}

bool RoadButton::canMove() const {
    return true;
}

bool RoadButton::isMoving() const {
    return _moving;
}


bool RoadButton::contains(int x, int y) const {
    if (x > getX()-5  &&  x < (getX() + 46 + 5) && y > getY()-5 && y < getY()+46 + 5) return true;
    return false;
}

void RoadButton::onClick() {
    if (_driver->getEditor()->getCurrentRow() >= 1 && _driver->getEditor()->getCurrentRow() <= 11) {
        _driver->getEditor()->setColor(new Fl_Color(FL_GRAY));
        _driver->getEditor()->addEnvironment(_driver->getEditor()->getCurrentRow(), 1);
        showConfigurationButtons();
    }
}

void RoadButton::resetPosition() {
    changePosition((700 / 2) - 23, 700);
}

void RoadButton::changeMovingState() {
    _moving = !_moving;
}

void RoadButton::changeState() {
    _displayed = !_displayed;
}

void RoadButton::changePosition(int loc_x, int loc_y) {
    _x = loc_x;
    _y = loc_y;
}

void RoadButton::showConfigurationButtons() {
    // Enables the configuration buttons to display at the right height
    std::vector<std::shared_ptr<Button>> buttons = _driver->getEditor()->getMenu()->getButtons();
    _driver->getEditor()->triggerSpeedButtons();
    _driver->getEditor()->triggerDirectionButtons();
    for (int i = 3; i < 10; i++) {
        if (i != 6 && i != 7) {
            int height = _driver->getEditor()->getWindowHeight();
            buttons.at(i)->changePosition(
                    buttons.at(i)->getX(),
                    (height - (height / 13.0f)) -
                    (_driver->getEditor()->getCurrentRow() * (height / 13.0) - ((height / 13.0) / 10)));
        }
    }
}