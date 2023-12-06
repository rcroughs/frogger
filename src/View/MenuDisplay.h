#ifndef FROGGER_MENUDISPLAY_H
#define FROGGER_MENUDISPLAY_H

#include "../Components/MenuComponents.h"

class MenuDisplay {
private:
    MenuComponents* components;
public:
    MenuDisplay(MenuComponents* components): components{components} {}
    void draw();
};


#endif //FROGGER_MENUDISPAY_H
