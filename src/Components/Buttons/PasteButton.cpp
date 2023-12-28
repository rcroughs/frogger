#include "PasteButton.h"
#include <Fl/Fl.H>
#include <Fl/Fl_Widget.H>
PasteButton::PasteButton(std::shared_ptr<TextInput> textInput, int x, int y): _textInput{std::move(textInput)}, _x{x}, _y{y} {
    image = new Fl_PNG_Image("res/paste.png");
}   

PasteButton::~PasteButton() {
    delete image;
}

int PasteButton::getX() {
    return _x;
}

int PasteButton::getY() {
    return _y;
}

bool PasteButton::contains(int x, int y) {
    if (x >= _x && x <= _x + 250 && y >= _y && y <= _y + 100) {
        return true;
    }
    return false;
}

bool PasteButton::canMove() {
    return false;
}

void PasteButton::resetPosition() {
    return;
}

bool PasteButton::isDisplayed() {
    return true;
}

bool PasteButton::isMoving() {
    return false;
}

void PasteButton::changeMovingState() {
    return;
}

void PasteButton::changeState() {
    return;
}

void PasteButton::onClick() {
    _textInput->pasteString(std::string(Fl::event_text()));
}

void PasteButton::changePosition(int loc_x, int loc_y) {
    _x = loc_x;
    _y = loc_y;
}

Fl_PNG_Image *PasteButton::getImage() {
    return image;
}