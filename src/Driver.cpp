#include "Driver.h"

#include "Model/Environments/SideWalk.h"
#include "Model/Environments/Water.h"
#include "Model/Environments/Road.h"

#include "View/GameRenderer.h"
#include "View/EditorRenderer.h"
#include "View/ViewHomeScreen.h"
#include "View/MenuDisplay.h"
#include "Controller/GameController.h"
#include "Controller/MenuController.h"
#include "Controller/EditorController.h"
#include "iostream"

void Driver::launchGame(Game* new_game) {
    delete controller;
    controller = new GameController(new_game);
    delete view;
    view = new GameRenderer(new_game, 700, 700);
    delete menu;
    gameState = ON_GAME;
}

void Driver::launchEditor() {
    delete game;
    delete editor;
    editor = new GameEditor(this, 700, 700);
    delete controller;
    controller = new EditorController(editor);
    delete view;
    view = new EditorRenderer(editor, 700, 700);
    delete menu;
    gameState = ON_EDIT;
    // A la fin : launchGame(game) dans GameEditor qui appelle via le driver
}

Game* Driver::CreateLevel1() {
    game = new Game(this);
    game->setGameMenu(new GameMenu(150, 100, this));
    Direction newDirection = up;
    game->setPlayer(new Player({45, 0}, newDirection));
    game->getMap()->setEnvironment(0, new SideWalk());
    for (int i = 1; i < 6; i++) {
        char circulation = '\0';
        float speedLimit = float(rand() % 3);
        if (speedLimit == 0) {speedLimit = 1;} else {speedLimit += 0.5;}
        if (i % 2 == 0) {circulation = 'r';} else {circulation = 'l';}
        game->getMap()->setEnvironment(i, new Road(circulation, speedLimit));
        game->getMap()->getEnvironment(i)->generateProps();
    }
    game->getMap()->setEnvironment(6, new SideWalk());
    for (int i = 7; i < 9; i++) {
        srand(clock());
        float speed = float(rand() % 3);
        if (speed == 0) {speed = 1;} else {speed -= 0.5;}
        game->getMap()->setEnvironment(i, reinterpret_cast<Environment *>(new Water(speed)));
        game->getMap()->getEnvironment(i)->generateProps(0);
    }
    game->getMap()->setEnvironment(9, new Water());
    game->getMap()->getEnvironment(9)->generateProps(2);
    for (int i = 10; i < 11; i++) {
        srand(clock());
        int random = rand();
        float speed = float((i + random) % 3 + 0.5);
        if (speed == 0) {speed = 1;}
        game->getMap()->setEnvironment(i, reinterpret_cast<Environment *>(new Water(speed)));
        game->getMap()->getEnvironment(i)->generateProps(0);
    }
    game->getMap()->setEnvironment(11, new Water());
    game->getMap()->getEnvironment(11)->generateProps(3);
    game->getMap()->setEnvironment(12, new Water());
    game->getMap()->getEnvironment(12)->generateProps(1);
    return game;
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
    } else if (gameState == ON_EDIT) {
        // Pour le moment
        view->draw();
        //updateMovement();
    }
}

Driver::Driver() : editor{nullptr}, view{nullptr}, controller{nullptr}, game{nullptr} {
    showHomeScreen();
}

Driver::~Driver() {
    if (gameState == ON_GAME) {
        deleteGame();
    } else {
        deleteMenu();
    }
}