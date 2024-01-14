#include "EditorController.h"
#include "../Model/GameEditor.h"
#include "../Model/EditorMenu.h"
#include "../Driver.h"
#include <FL/Enumerations.H>
#include <memory>

EditorController::EditorController(std::shared_ptr<GameEditor> editor)
    : _editor{std::move(editor)} {}

void EditorController::mouseMove(short loc_x, short loc_y) {
  if (!_editor->isPaused()) {
    _editor->changeCurrentRow((700 - (loc_y)) / (int(float(700) / 13.0f)));
    for (auto &button : _editor->getMenu()->getButtons()) {
      if (button->isDisplayed() && button->canMove() && button->isMoving()) {
        button->changePosition(loc_x, loc_y);
      }
    }
  }
}

void EditorController::mouseClick(short loc_x, short loc_y) {

  if (_editor->isPaused()) {
    std::vector<std::shared_ptr<Button>> buttons = _editor->getPauseMenu()->getButtons();
    for (auto &button : buttons) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        return;
      }
    }
    return;
  }

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
          if (_editor->timeOutValid()) {
              button->onClick();
          }
      }
        // Launch Mario Maker game
        if (_editor->getEnviNumber() == 12) {
            _editor->triggerEnvironmentButton();
            _editor->getDriver()->launchLevelFromEditor();
        }
    }
  }
}

void EditorController::keyPressed(int keycode) { 
  if (keycode == FL_Escape) {
    _editor->triggerPauseMenu();
  }
 }

void EditorController::keyReleased(int keycode) { static_cast<void>(keycode); }

void EditorController::updateMovement() { return; }

void EditorController::mouseRelease(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}