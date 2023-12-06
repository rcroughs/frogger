#include "Driver.h"
#include "View/GameRenderer.h"
#include "View/ViewHomeScreen.h"
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
    gameState = ON_GAME;
}

void Driver::deleteGame() {
    delete game;
    delete view;
    delete controller;
}

void Driver::showMenu() {
    menu = new MenuComponents(this);
    if (gameState == ON_GAME || gameState == HOME_SCREEN) {
        delete view;
    }
    view = new MenuDisplay(menu);
    if (gameState == ON_GAME) {
        delete controller;
    }
    controller = new MenuController(menu);
    if (gameState == ON_GAME) {
        delete game;
    }
    gameState = MENU;
}

void Driver::deleteMenu() {
    delete menu;
    delete view;
    delete controller;
}

void Driver::showHomeScreen() {
    view = new ViewHomeScreen();
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
    } else if (gameState == HOME_SCREEN) {
        view->draw();
        homescreen++;
        if (homescreen == 60) {
            showMenu();
        }
    }
}

Driver::Driver() {
    showHomeScreen();
}

Driver::~Driver() {
    if (gameState == ON_GAME) {
        deleteGame();
    } else {
        deleteMenu();
    }
}