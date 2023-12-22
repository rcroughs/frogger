//
// Created by romek on 11/30/23.
//

#include "LilyPad.h"

LilyPad::LilyPad(float leftCornerPos) :  leftCorner{leftCornerPos}, hasTurtle{false} {
    Fl_PNG_Image largeImage = Fl_PNG_Image("res/lilypad.png");
    image = (Fl_PNG_Image*) largeImage.copy(50, 50);
}

void LilyPad::handleGame(Game* currentGame) {
    if (hasTurtle) {
        currentGame->killPlayer();
    } else {
        hasTurtle = true;
        currentGame->win();
    }
}