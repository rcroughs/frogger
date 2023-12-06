#ifndef FROGGER_DRIVER_H
#define FROGGER_DRIVER_H

#include "View/View.h"
#include "Controller/Controller.h"
#include "Model/Game.h"
#include "Components/MenuComponents.h"

class MenuComponents;
class Game;

class Driver {
private:
    View* view;
    Controller* controller;
    Game* game;
    MenuComponents* menu;
    enum GAME_STATE {
        MENU,
        ON_GAME,
        HOME_SCREEN
    };
    GAME_STATE gameState {HOME_SCREEN};
    int homescreen;
public:
    Driver();
    ~Driver();
    virtual void launchGame();
    virtual void deleteGame();
    virtual void showMenu();
    virtual void deleteMenu();
    virtual void showHomeScreen();
    virtual void refresh();

    virtual void mouseMove(short loc_x, short loc_y) {if (controller != nullptr) controller->mouseMove(loc_x, loc_y);}
    virtual void mouseClick(short loc_x, short loc_y) {if (controller != nullptr) controller->mouseClick(loc_x, loc_y);}
    virtual void keyPressed(int keycode) {if (controller != nullptr) controller->keyPressed(keycode);}
    virtual void keyReleased(int keycode) {if (controller != nullptr) controller->keyReleased(keycode);}
    virtual void updateMovement() {if (controller != nullptr) controller->updateMovement();}
};


#endif //FROGGER_DRIVER_H
