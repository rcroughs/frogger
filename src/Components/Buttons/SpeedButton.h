#ifndef SRC_SPEEDX1ROAD_H
#define SRC_SPEEDX1ROAD_H

#include "FL/Fl_PNG_Image.H"
#include "../Button.h"

class Driver;

class SpeedButton : public Button {
private:
    Fl_PNG_Image* image;
    Driver* driver;
    int x;
    int y;
    short id; // 0, 1 or 2
    bool displayed{false};
public:
    SpeedButton(int x, int y, Driver* driver, short id);
    ~SpeedButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual short getId() {return id;}
    virtual bool contains(int x, int y);
    virtual void onClick();
    virtual void resetPosition() {}
    virtual bool isDisplayed() {return displayed;}
    virtual bool canMove() {return false;}
    virtual bool isMoving() {return false;}
    virtual void changePosition(int loc_x, int loc_y) {x = loc_x; y = loc_y;}
    virtual void changeMovingState() {}
    virtual void changeState() {displayed = !displayed;}
};

#endif //SRC_SPEEDX1ROAD_H
