#include "Driver.h"
#include "View/GameRenderer.h"
#include "View/MenuDisplay.h"
#include "Controller/GameController.h"
#include "Controller/MenuController.h"
#include "iostream"

void Driver::launchGame() {
    game = new Game();
    view = new GameRenderer(game, 700, 700);
    controller = new GameController(game);
    gameState = ON_GAME;
}

void Driver::deleteGame() {
    delete game;
    delete view;
    delete controller;
}

void Driver::showMenu() {
    menu = new MenuComponents(this);
    view = new MenuDisplay(menu);
    controller = new MenuController(menu);
    gameState = MENU;
}

void Driver::deleteMenu() {
    delete menu;
    delete view;
    delete controller;
}

void Driver::refresh() {
    if (gameState == MENU) {
        menu->update();
        view->draw();
    } else if (gameState == ON_GAME) {
        game->update();
        view->draw();
        updateMovement();
    }
}

Driver::Driver() {
    showMenu();
}

Driver::~Driver() {
    if (gameState == ON_GAME) {
        deleteGame();
    } else {
        deleteMenu();
    }
}