#ifndef FROGGER_MENUCONTROLLER_H
#define FROGGER_MENUCONTROLLER_H

#include "Controller.h"
#include "../Components/MenuComponents.h"

class MenuController : public Controller {
private:
    MenuComponents* menu;
public:
    MenuController(MenuComponents* menu) : menu{menu} {}

    virtual void mouseMove(short loc_x, short loc_y) override {};
    virtual void mouseClick(short loc_x, short loc_y) override;
    virtual void keyPressed(int keycode) override {};
    virtual void keyReleased(int keycode) override {};
    virtual void updateMovement() override {};
};


#endif //FROGGER_MENUCONTROLLER_H
