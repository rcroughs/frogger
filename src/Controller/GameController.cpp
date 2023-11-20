#include "GameController.h"

void GameController::keyPressed(int keycode) {
    game.modifyPlayer(keycode);
}

