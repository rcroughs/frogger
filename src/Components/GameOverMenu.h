#ifndef _FROGGER_GAMEOVERMENU_H_
#define _FROGGER_GAMEOVERMENU_H_

#include "Button.h"
#include "../Driver.h"
#include <FL/Fl_PNG_Image.H>
#include <vector>

class Driver;

class GameOverMenu {
public:
  GameOverMenu(Driver *driver);
  ~GameOverMenu();
  Fl_PNG_Image *getImage() { return image; }
  std::vector<Button *> getButtons() { return buttons; }

private:
  Driver *driver;
  std::vector<Button *> buttons;
  Fl_PNG_Image *image;
};

#endif // _FROGGER_WINNINGMENU_H_