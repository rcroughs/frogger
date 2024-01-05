#include "MenuController.h"
#include "vector"

MenuController::MenuController(std::shared_ptr<MenuComponents> menu)
    : _menu{std::move(menu)} {}

void MenuController::mouseMove(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}

void MenuController::mouseClick(short loc_x, short loc_y) {
  std::vector<std::shared_ptr<Button>> buttons = _menu->getButtons();
  bool buttonFound = false;
  for (auto &button : buttons) {
    if (!buttonFound) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        buttonFound = true;
      }
    }
  }
}

void MenuController::mouseRelease(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}

void MenuController::keyPressed(int keycode) { static_cast<void>(keycode); }

void MenuController::keyReleased(int keycode) { static_cast<void>(keycode); }

void MenuController::updateMovement() { return; }