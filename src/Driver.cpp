#include "Driver.h"
#include "View/GameRenderer.h"
#include "View/MenuDisplay.h"
#include "Controller/GameController.h"
#include "Controller/MenuController.h"
#include "iostream"

void Driver::launchGame() {
    game = new Game(this);
    delete controller;
    controller = new GameController(game);
    delete view;
    view = new GameRenderer(game, 700, 700);
    delete menu;
    hasGame = true;
    hasMenu = false;
    gameState = ON_GAME;
}

void Driver::deleteGame() {
    delete game;
    delete view;
    delete controller;
}

void Driver::showMenu() {
    menu = new MenuComponents(this);
    if (hasGame) {
        delete view;
    }
    view = new MenuDisplay(menu);
    if (hasGame) {
        delete controller;
    }
    controller = new MenuController(menu);
    if (hasGame) {
        delete game;
    }
    hasMenu = true;
    hasGame = false;
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
        if (!game->isOnPause()) {
            game->update();
        }
        view->draw();
        updateMovement();
    }
}

Driver::Driver() {
    showMenu();
    hasMenu = true;
}

Driver::~Driver() {
    if (gameState == ON_GAME) {
        deleteGame();
    } else {
        deleteMenu();
    }
}