#include "LilyPad.h"
#include <FL/Enumerations.H>

LilyPad::LilyPad(float leftCornerPos)
    : _leftCorner{leftCornerPos}, _hasTurtle{false} {
  Fl_PNG_Image largeImage = Fl_PNG_Image("res/lilypad.png");
  _image = (Fl_PNG_Image *)largeImage.copy(50, 50);
}

LilyPad::~LilyPad() { delete _image; }

float LilyPad::getPosition() const { return _leftCorner; }

float LilyPad::getRightCorner() const { return _leftCorner + _size; }

Fl_Color LilyPad::getColor() const { return FL_GREEN; }

float LilyPad::getSize() const { return _size; }

bool LilyPad::contains(float playerPosition) const {
  return getPosition() - 3 < playerPosition && playerPosition < getRightCorner() -2;
}

void LilyPad::move() { return; }

void LilyPad::handleGame(Game* currentGame) {
    if (_hasTurtle) {
        currentGame->killPlayer();
    } else {
        _hasTurtle = true;
        currentGame->win();
    }
}

bool LilyPad::hasImage() const { return true; };

Fl_PNG_Image *LilyPad::getImage() const { return _image; };

bool LilyPad::isVisible() const { return true; };

void LilyPad::update() { return; }