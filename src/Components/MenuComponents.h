#ifndef FROGGER_MENUCOMPONENTS_H
#define FROGGER_MENUCOMPONENTS_H

#include <vector>
#include "Button.h"
#include "Cloud.h"
#include "FL/Fl_PNG_Image.H"
#include "../Driver.h"

class Driver;

class MenuComponents {
private:
    Fl_PNG_Image* logo;
    Fl_PNG_Image* bg;
    std::vector<Cloud> clouds;
    std::vector<Button*> buttons;
    Driver* driver;
public:
    MenuComponents(Driver* driver);
    ~MenuComponents();
    Fl_PNG_Image* getLogo() {return logo;}
    Fl_PNG_Image* getBackground() {return bg;}
    std::vector<Button*> getButtons() {return buttons;}
    std::vector<Cloud>* getClouds() {return &clouds;};

    void update();
};


#endif //FROGGER_MENUCOMPONENTS_H
