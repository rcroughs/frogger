#ifndef SRC_EDITORMENU_H
#define SRC_EDITORMENU_H

#include "vector"
#include "../Components/Button.h"
#include "FL/Fl_PNG_Image.H"
#include "../Driver.h"

class Driver;

class EditorMenu {
private:
    std::vector<Button*> buttons;
    Driver* driver;
public:
    EditorMenu(Driver* driver);
    ~EditorMenu();

    std::vector<Button*> getButtons() {return buttons;}
    //virtual void updatePosition(Position mouseloc) {};
};


#endif //SRC_EDITORMENU_H
