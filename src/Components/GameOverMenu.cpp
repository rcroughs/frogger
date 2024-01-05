#include "GameOverMenu.h"
#include "Buttons/MenuButton.h"
#include "Buttons/PlayAgainButton.h"

GameOverMenu::GameOverMenu(Driver *driver) {
  _image = new Fl_PNG_Image("res/gameover.png");
  _buttons.push_back(std::make_shared<PlayAgainButton>(250, 520, driver));
  _buttons.push_back(std::make_shared<MenuButton>(250, 400, driver));
}

GameOverMenu::~GameOverMenu() {
  delete _image;
}

Fl_PNG_Image *GameOverMenu::getImage() const { return _image; }

std::vector<std::shared_ptr<Button>> GameOverMenu::getButtons() const {
  return _buttons;
}