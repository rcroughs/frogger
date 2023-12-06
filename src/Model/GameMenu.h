#ifndef FROGGER_MENU_H
#define FROGGER_MENU_H

#include "vector"
#include "../Components/Button.h"
#include "FL/Fl_PNG_Image.H"
#include "../Driver.h"

class Driver;

class GameMenu {
private:
    int x;
    int y;
    std::vector<Button*> buttons;
    Fl_PNG_Image* image;
    Driver* driver;
public:
    GameMenu(int x, int y, Driver* driver);
    ~GameMenu();
    int getX() {return x;}
    int getY() {return y;}
    std::vector<Button*> getButtons() {return buttons;}
    Fl_PNG_Image* getImage() {return image;}

};


#endif //FROGGER_MENU_H
