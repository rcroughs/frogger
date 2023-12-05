#ifndef FROGGER_BUTTONS_H
#define FROGGER_BUTTONS_H

#include <string>
#include <FL/Fl_PNG_Image.H>

class Button {
public:
    virtual Fl_PNG_Image* getImage() =0;
    virtual int getX() =0;
    virtual int getY() =0;
    virtual bool contains(int x, int y) =0;
    virtual void onClick() =0;
};


#endif //FROGGER_BUTTONS_H
