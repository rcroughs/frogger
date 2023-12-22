#include "WinningMenu.h"
#include "Buttons/MenuButton.h"
#include "Buttons/PlayAgainButton.h"

WinningMenu::WinningMenu(Driver *driver) {
  image = new Fl_PNG_Image("res/victory.png");
  buttons.push_back(new PlayAgainButton(250, 520, driver));
  buttons.push_back(new MenuButton(250, 400, driver));
}

WinningMenu::~WinningMenu() {
  delete image;
  for (auto &button : buttons) {
    delete button;
  }
}