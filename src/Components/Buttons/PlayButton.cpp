#include "PlayButton.h"
#include "../../Driver.h"
#include "iostream"

PlayButton::PlayButton(int x, int y, Driver* driver) : x{x}, y{y}, driver{driver} {
    image = new Fl_PNG_Image("res/play.png");
}

bool PlayButton::contains(int x, int y) {
    if (this->x < x && x < this->x + 200 && y < this->y + 100 && this->y < y) return true;
    return false;
}

void PlayButton::onClick() {
    driver->launchGame();
}