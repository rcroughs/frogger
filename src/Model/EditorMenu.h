#ifndef SRC_EDITORMENU_H
#define SRC_EDITORMENU_H

#include "../Components/Button.h"
#include "../Driver.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>
#include <vector>

class Driver;

class EditorMenu {
public:
  EditorMenu(Driver* driver);

  std::vector<Button *> getButtons() { return buttons; }
  // virtual void updatePosition(Position mouseloc) {};

private:
  std::vector<Button *> buttons;
  Driver* driver;
};

#endif // SRC_EDITORMENU_H
