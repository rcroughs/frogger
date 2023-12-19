#include "EditorController.h"

void EditorController::mouseClick(short loc_x, short loc_y) {

    std::vector<Button*> buttons = editor->getMenu()->getButtons();

    for (auto &button : buttons) {
        if (button->isDisplayed() && button->contains(loc_x, loc_y)) {
            // Cas des boutons d'environnement
            if (button->canMove()) {
                if (button->isMoving()) {
                    button->onClick();
                    editor->triggerEnvironmentButton();
                    button->resetPosition();
                }
                button->changeMovingState();
            }
            else {
                // Boutons de configuration
                button->onClick();
            }

        }
    }
}

void EditorController::mouseMove(short loc_x, short loc_y) {
    editor->changeCurrentRow((700 - (loc_y))/(int(float(700) / 13.0f)));
    for (auto &button : editor->getMenu()->getButtons()) {
        if (button->isDisplayed() && button->canMove() && button->isMoving()) {
            button->changePosition(loc_x, loc_y);
        }
    }
}
