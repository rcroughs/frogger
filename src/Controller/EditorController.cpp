#include "EditorController.h"
#include <memory>

EditorController::EditorController(std::shared_ptr<GameEditor> editor)
    : _editor{std::move(editor)} {}

void EditorController::mouseMove(short loc_x, short loc_y) {
  _editor->changeCurrentRow((700 - (loc_y)) / (int(float(700) / 13.0f)));
  for (auto &button : _editor->getMenu()->getButtons()) {
    if (button->isDisplayed() && button->canMove() && button->isMoving()) {
      button->changePosition(loc_x, loc_y);
    }
  }
}

void EditorController::mouseClick(short loc_x, short loc_y) {

  std::vector<std::shared_ptr<Button>> buttons = _editor->getMenu()->getButtons();

  for (auto &button : buttons) {
    if (button->isDisplayed() && button->contains(loc_x, loc_y)) {
      // Cas des boutons d'environnement
      if (button->canMove()) {
        if (button->isMoving()) {
            if (_editor->getCurrentRow() >= 1 && _editor->getCurrentRow() <= 11) {
                button->onClick();
                _editor->triggerEnvironmentButton();
                button->resetPosition();
            }
        }
        button->changeMovingState();
      } else {
        // Boutons de configuration
        button->onClick();
      }
        // Launch Mario Maker game
        if (_editor->getEnviNumber() == 12) {
            _editor->triggerEnvironmentButton();
            _editor->getDriver()->launchLevelFromEditor();
        }
    }
  }
}

void EditorController::keyPressed(int keycode) { static_cast<void>(keycode); }

void EditorController::keyReleased(int keycode) { static_cast<void>(keycode); }

void EditorController::updateMovement() { return; }

void EditorController::mouseRelease(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}