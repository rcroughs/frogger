#ifndef FROGGER_VIEWHOMESCREEN_H
#define FROGGER_VIEWHOMESCREEN_H

#include "View.h"
#include "FL/Fl_PNG_Image.H"

class ViewHomeScreen : public View {
    Fl_PNG_Image* image;
public:
    ViewHomeScreen();
    ~ViewHomeScreen();
    virtual void draw() override;
};


#endif //FROGGER_VIEWHOMESCREEN_H
