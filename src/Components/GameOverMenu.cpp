#include "GameOverMenu.h"
#include "Buttons/MenuButton.h"
#include "Buttons/PlayAgainButton.h"

GameOverMenu::GameOverMenu(Driver *driver) {
  image = new Fl_PNG_Image("res/gameover.png");
  buttons.push_back(new PlayAgainButton(250, 520, driver));
  buttons.push_back(new MenuButton(250, 400, driver));
}

GameOverMenu::~GameOverMenu() {
  delete image;
  for (auto &button : buttons) {
    delete button;
  }
}