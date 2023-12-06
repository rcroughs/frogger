#ifndef FROGGER_MENUDISPLAY_H
#define FROGGER_MENUDISPLAY_H

#include "../Components/MenuComponents.h"
#include "View.h"

class MenuDisplay : public View {
private:
    MenuComponents* components;
public:
    MenuDisplay(MenuComponents* components): components{components} {}
    void draw() override;
};


#endif //FROGGER_MENUDISPAY_H
