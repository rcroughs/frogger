//
// Created by romek on 11/30/23.
//

#include "LilyPad.h"

void LilyPad::handleGame(Game* currentGame) {
    currentGame->changeWinningState();
}