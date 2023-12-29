#include "LevelSelectorDisplay.h"
#include <FL/fl_draw.H>

LevelSelectorDisplay::LevelSelectorDisplay(std::shared_ptr<LevelSelector> levelSelector) : _levelSelector{std::move(levelSelector)} {}

void LevelSelectorDisplay::draw() {
    _levelSelector->getBg()->draw(0, 0);
    for (auto button : _levelSelector->getButtons()) {
        button->getImage()->draw(button->getX(), button->getY());
        fl_font(FL_HELVETICA_BOLD, 35);
        fl_draw(button->getName().c_str(), button->getX() + 100, button->getY() + 100);
        fl_draw(button->getAuthor().c_str(), button->getX() + 100, button->getY() + 175);
    }
    _levelSelector->getMenuButton()->getImage()->draw(_levelSelector->getMenuButton()->getX(), _levelSelector->getMenuButton()->getY());
    if (_levelSelector->getAddMapMenu()->isOpen()) {
        _levelSelector->getAddMapMenu()->getImage()->draw(50, 30);
        for (auto &textInput : _levelSelector->getAddMapMenu()->getTextInputs()) {
            textInput->getImage()->draw(textInput->getX(), textInput->getY());
            if (textInput->isEmpty() && !textInput->isActive())
              fl_draw(textInput->getLabel().c_str(), textInput->getX() + 10,
                      textInput->getY() + 10);
            else {
              fl_draw(textInput->getInput().c_str(), textInput->getX() + 10,
                      textInput->getY() + 10);
            }
        }
        for (auto &button : _levelSelector->getAddMapMenu()->getButtons()) {
            button->getImage()->draw(button->getX(), button->getY());
        }
    }
}