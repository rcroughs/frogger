#include "DirectionButton.h"
#include "../../Driver.h"
#include "iostream"



DirectionButton::DirectionButton(int x, int y, Driver *driver, short id) : x{x}, y{y}, driver{driver}, id{id} {
    if (id == 0) {
        image = new Fl_PNG_Image("res/left.png");
    }
    else { // id = 1;
        image = new Fl_PNG_Image("res/right.png");
    }
}

bool DirectionButton::contains(int x, int y) {
    if (x > getX()  &&  x < (getX() + 46) && y > getY() && y < getY()+50) return true;
    return false;
}

void DirectionButton::onClick() {
    changeState();
    if (getId() == 0) {
        driver->getEditor()->modifyRoadCirculation('l');
    } else {
        driver->getEditor()->modifyRoadCirculation('r');
    }
    driver->getEditor()->addEnvironment(driver->getEditor()->getCurrentRow(), 1);
}

