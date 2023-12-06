#ifndef FROGGER_MENUBUTTON_H
#define FROGGER_MENUBUTTON_H

#include "../Button.h"
#include "../../Driver.h"

class MenuButton : public Button {
private:
    Fl_PNG_Image* image;
    Driver* driver;
    int x;
    int y;
public:
    MenuButton(int x, int y, Driver* driver);
    ~MenuButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual bool contains(int x, int y);
    virtual void onClick();
};


#endif //FROGGER_MENUBUTTON_H
