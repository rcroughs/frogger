#include "ViewHomeScreen.h"

ViewHomeScreen::ViewHomeScreen() {
    image = new Fl_PNG_Image("res/homescreen.png");
}

ViewHomeScreen::~ViewHomeScreen() {
    delete image;
}

void ViewHomeScreen::draw() {
    image->draw(0,0);
}