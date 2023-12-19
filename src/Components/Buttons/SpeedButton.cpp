#include "SpeedButton.h"
#include "../../Driver.h"
#include "iostream"

SpeedButton::SpeedButton(int x, int y, Driver *driver, short id) : x{x}, y{y}, driver{driver}, id{id} {
    if (id == 0) {
        image = new Fl_PNG_Image("res/speed_1.png");
    }
    else if (id == 1) {
        image = new Fl_PNG_Image("res/speed_2.png");
    }
    else { // id = 2;
        image = new Fl_PNG_Image("res/speed_3.png");
    }
}

bool SpeedButton::contains(int x, int y) {
    if (x > getX()  &&  x < (getX() + 46) && y > getY() && y < getY()+50) return true;
    return false;
}

void SpeedButton::onClick() {
    // Va modifier les paramètres pour les deux environnements
    // Une fois qu'un environnements est placé, tous ces paramètres sont reset
    switch(getId()) {
        case 0:
            driver->getEditor()->modifyWaterFlow(0.5);
            driver->getEditor()->modifyRoadSpeedLimit(1);
            break;
        case 1:
            driver->getEditor()->modifyWaterFlow(1);
            driver->getEditor()->modifyRoadSpeedLimit(1.5);
            break;
        case 2:
            driver->getEditor()->modifyWaterFlow(1.5);
            driver->getEditor()->modifyRoadSpeedLimit(2.5);
    }
}
