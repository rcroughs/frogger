#ifndef FROGGER_PLAYBUTTON_H
#define FROGGER_PLAYBUTTON_H

#include "FL/Fl_PNG_Image.H"
#include "../Button.h"

class PlayButton : public Button {
private:
    Fl_PNG_Image* image;
    int x;
    int y;
public:
    PlayButton(int x, int y);
    ~PlayButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual bool contains(int x, int y) {};
    virtual void onClick() {};
};


#endif //FROGGER_PLAYBUTTON_H
