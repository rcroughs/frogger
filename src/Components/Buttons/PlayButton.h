#ifndef FROGGER_PLAYBUTTON_H
#define FROGGER_PLAYBUTTON_H

#include "FL/Fl_PNG_Image.H"
#include "../Button.h"

class Driver;

class PlayButton : public Button {
private:
    Fl_PNG_Image* image;
    Driver* driver;
    int x;
    int y;
public:
    PlayButton(int x, int y, Driver* driver);
    ~PlayButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual bool contains(int x, int y);
    virtual bool canMove() {return false;}
    virtual void onClick();
    virtual void resetPosition() {};
    virtual bool isDisplayed() {return false;}
    virtual bool isMoving() {return false;}
    virtual void changeMovingState() {}
    virtual void changePosition(int loc_x, int loc_y) {x = loc_x; y = loc_y;}
    virtual void changeState() {}
};


#endif //FROGGER_PLAYBUTTON_H
