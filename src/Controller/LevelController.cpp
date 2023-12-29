#include "LevelController.h"

void LevelController::mouseMove(short loc_x, short loc_y) {}

void LevelController::mouseClick(short loc_x, short loc_y) {
  if (_levelSelector->getAddMapMenu()->isOpen()) {
    for (auto &button : _levelSelector->getAddMapMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        return;
      }
    }
    for (auto &textInput : _levelSelector->getAddMapMenu()->getTextInputs()) {
      if (textInput->contains(loc_x, loc_y)) {
        for (auto &textInput :
             _levelSelector->getAddMapMenu()->getTextInputs()) {
                textInput->resetActivity();
             }
          textInput->changeActivity();
          return;
        }
      }
    }
    if (_levelSelector->getMenuButton()->contains(loc_x, loc_y)) {
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

  void LevelController::mouseRelease(short loc_x, short loc_y) {}

  void LevelController::keyPressed(int keycode) {
    if (keycode == FL_Up) {
        _levelSelector->scrollUp();
    } else if (keycode == FL_Down) {
        _levelSelector->scrollDown();
    } else if (keycode == 'p') {
        _levelSelector->getAddMapMenu()->changeState();
    }
    if (_levelSelector->getAddMapMenu()->isOpen()) {
      for (auto &textInput : _levelSelector->getAddMapMenu()->getTextInputs()) {
        if (textInput->isActive()) {
          if (keycode == FL_BackSpace) {
            textInput->removeChar();
          } else if (keycode == FL_Enter) {
            textInput->changeActivity();
          } else {
            textInput->addChar(keycode);
          }
        }
      }
    }
}

void LevelController::keyReleased(int keycode) {}

void LevelController::updateMovement() {}