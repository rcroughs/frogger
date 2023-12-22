#ifndef _FROGGER_WINNINGMENU_H_
#define _FROGGER_WINNINGMENU_H_

#include "Button.h"
#include <FL/Fl_PNG_Image.H>
#include <vector>

class Driver;

class WinningMenu {
public:
  WinningMenu(Driver *driver);
  ~WinningMenu();
  Fl_PNG_Image *getImage() { return image; }
  std::vector<Button *> getButtons() { return buttons; }

private:
  Driver *driver;
  std::vector<Button *> buttons;
  Fl_PNG_Image *image;
};

#endif // _FROGGER_WINNINGMENU_H_