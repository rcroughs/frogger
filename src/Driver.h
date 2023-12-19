#ifndef FROGGER_DRIVER_H
#define FROGGER_DRIVER_H

#include "View/View.h"
#include "Controller/Controller.h"
#include "Components/MenuComponents.h"
#include "Model/GameEditor.h"

class MenuComponents;
class Game;
class GameEditor;

class Driver {
private:
    View* view;
    Controller* controller;
    Game* game;
    GameEditor* editor;
    MenuComponents* menu;
    enum GAME_STATE {
        MENU,
        ON_GAME,
        HOME_SCREEN,
        ON_EDIT
    };
    GAME_STATE gameState {HOME_SCREEN};
    int homescreen;
public:
    Driver();
    ~Driver();
    virtual void launchGame(Game* new_game);
    virtual void launchEditor();
    virtual void deleteGame();
    virtual void showMenu();
    virtual void deleteMenu();
    virtual void showHomeScreen();
    virtual void refresh();

    // Levels
    virtual Game* CreateLevel1();

    virtual void mouseMove(short loc_x, short loc_y) {if (controller != nullptr) controller->mouseMove(loc_x, loc_y);}
    virtual void mouseClick(short loc_x, short loc_y) {if (controller != nullptr) controller->mouseClick(loc_x, loc_y);}
    virtual void mouseReleased(short loc_x, short loc_y) {if (controller != nullptr && gameState == ON_EDIT) controller->mouseRelease(loc_x, loc_y);}
    virtual void keyPressed(int keycode) {if (controller != nullptr) controller->keyPressed(keycode);}
    virtual void keyReleased(int keycode) {if (controller != nullptr) controller->keyReleased(keycode);}
    virtual void updateMovement() {if (controller != nullptr) controller->updateMovement();}

    virtual GameEditor* getEditor() {return editor;}
};


#endif //FROGGER_DRIVER_H
