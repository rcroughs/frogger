#include "MenuController.h"
#include "vector"

void MenuController::mouseClick(short loc_x, short loc_y) {
    std::vector<Button*> buttons = menu->getButtons();
    for (auto &button : buttons) {
        if (button->contains(loc_x, loc_y)) {
            button->onClick();
        }
    }
}
