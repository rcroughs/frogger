#ifndef FROGGER_DRIVER_H
#define FROGGER_DRIVER_H

#include "View/View.h"
#include "Controller/Controller.h"
#include "Model/Game.h"
#include "Components/MenuComponents.h"

class MenuComponents;

class Driver {
private:
    View* view;
    Controller* controller;
    Game* game;
    MenuComponents* menu;
    enum GAME_STATE {
        MENU,
        ON_GAME
    };
    GAME_STATE gameState {MENU};
public:
    Driver();
    ~Driver();
    virtual void launchGame();
    virtual void deleteGame();
    virtual void showMenu();
    virtual void deleteMenu();
    virtual void refresh();

    virtual void mouseMove(short loc_x, short loc_y) {controller->mouseMove(loc_x, loc_y);}
    virtual void mouseClick(short loc_x, short loc_y) {controller->mouseClick(loc_x, loc_y);}
    virtual void keyPressed(int keycode) {controller->keyPressed(keycode);}
    virtual void keyReleased(int keycode) {controller->keyReleased(keycode);}
    virtual void updateMovement() {controller->updateMovement();}
};


#endif //FROGGER_DRIVER_H
