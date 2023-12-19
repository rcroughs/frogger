#ifndef SRC_WATERBUTTON_H
#define SRC_WATERBUTTON_H

#include "FL/Fl_PNG_Image.H"
#include "../Button.h"
#include "iostream"

class Driver;

class WaterButton : public Button {
private:
    Fl_PNG_Image* image;
    Driver* driver;
    int x;
    int y;
    bool displayed{true};
    bool moving{false};
public:
    WaterButton(int x, int y, Driver* driver);
    ~WaterButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual bool contains(int x, int y);
    virtual void onClick();
    virtual void resetPosition() {changePosition(((700/3)/2)-23,700);}
    virtual bool isDisplayed() {return displayed;}
    virtual bool canMove() {return true;}
    virtual bool isMoving() {return moving;}
    virtual void changeMovingState() {moving = !moving;}
    virtual void changeState() {displayed = !displayed;}
    virtual void changePosition(int loc_x, int loc_y) {x = loc_x; y = loc_y;}
    virtual void showConfigurationButtons();
};

#endif //SRC_WATERBUTTON_H
