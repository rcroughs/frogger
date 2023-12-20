#ifndef FROGGER_MENU_H
#define FROGGER_MENU_H

#include "../Components/Button.h"
#include "../Driver.h"
#include "FL/Fl_PNG_Image.H"
#include <vector>
#include <memory>

class Driver;

class GameMenu {
public:
  GameMenu(int x, int y, Driver* driver);
  ~GameMenu();
  int getX() { return _x; }
  int getY() { return _y; }
  std::vector<Button *> getButtons() { return _buttons; }
  std::shared_ptr<Fl_PNG_Image> getImage() { return _image; }

private:
  int _x;
  int _y;
  std::vector<Button *> _buttons;
  std::shared_ptr<Fl_PNG_Image> _image;
  Driver* _driver;

};

#endif // FROGGER_MENU_H
