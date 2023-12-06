#include "MenuButton.h"

MenuButton::MenuButton(int x, int y, Driver* driver) : x{x}, y{y}, driver{driver} {
    image = new Fl_PNG_Image("res/menu.png");
}

bool MenuButton::contains(int x, int y) {
    if (this->x < x && x < this->x + 200 && y < this->y + 100 && this->y < y) return true;
    return false;
}

void MenuButton::onClick() {
    driver->showMenu();
}
