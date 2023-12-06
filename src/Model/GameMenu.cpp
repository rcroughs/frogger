#include "GameMenu.h"
#include "../Components/Buttons/MenuButton.h"
#include "../Components/Buttons/QuitButton.h"

GameMenu::GameMenu(int x, int y, Driver* driver) : x{x}, y{y}, driver{driver} {
    image = new Fl_PNG_Image("res/pause.png");
    buttons.push_back(new MenuButton(250, 275, driver));
    buttons.push_back(new QuitButton(250, 400));
}

GameMenu::~GameMenu() {
    for (auto &button : buttons) {
        delete button;
    }
}