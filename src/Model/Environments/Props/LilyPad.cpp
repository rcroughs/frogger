//
// Created by romek on 11/30/23.
//

#include "LilyPad.h"

void LilyPad::handleGame(Game* currentGame) {
    if (hasTurtle) {
        currentGame->killPlayer();
    } else {
        hasTurtle = true;
        currentGame->win();
    }
}