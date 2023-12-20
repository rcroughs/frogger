#include "RoadButton.h"
#include "../../Driver.h"
#include "iostream"
#include <memory>

RoadButton::RoadButton(int x, int y, Driver* driver) : x{x}, y{y}, driver{driver} {
    image = new Fl_PNG_Image("res/road_button.png");
}

bool RoadButton::contains(int x, int y) {
    if (x > getX()-5  &&  x < (getX() + 46 + 5) && y > getY()-5 && y < getY()+46 + 5) return true;
    return false;
}

void RoadButton::onClick() {
    if (driver->getEditor()->getCurrentRow() >= 0 && driver->getEditor()->getCurrentRow() <= 12) {
        driver->getEditor()->setColor(new Fl_Color(FL_GRAY));
        driver->getEditor()->addEnvironment(driver->getEditor()->getCurrentRow(), 2);
    }
}