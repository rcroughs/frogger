#include "LevelController.h"

LevelController::LevelController(std::shared_ptr<LevelSelector> levelSelector)
    : _levelSelector{std::move(levelSelector)} {}

void LevelController::mouseMove(short loc_x, short loc_y) {
  // unused parameters
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}

void LevelController::mouseClick(short loc_x, short loc_y) {
    if(_levelSelector->getMenuButton()->contains(loc_x, loc_y)) {
        _levelSelector->getMenuButton()->onClick();
        return;
    }
    for (auto button : _levelSelector->getButtons()) {
        if (button->contains(loc_x, loc_y)) {
            button->onClick();
            return;
        }
    }
}

void LevelController::mouseRelease(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}

void LevelController::keyPressed(int keycode) {
    if (keycode == FL_Up) {
        _levelSelector->scrollUp();
    } else if (keycode == FL_Down) {
        _levelSelector->scrollDown();
    }
}

void LevelController::keyReleased(int keycode) { static_cast<void>(keycode);}

void LevelController::updateMovement() {}