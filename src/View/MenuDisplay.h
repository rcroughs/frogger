////////// Menu View Header File - src/View/MenuDisplay.h //////////
// Description: This class draw the menu.
// Constructor takes: Components of the menu
////////// FROGGER ///////////////////////////////////

#ifndef _FROGGER_MENUDISPLAY_H
#define _FROGGER_MENUDISPLAY_H

#include "../Components/MenuComponents.h"
#include "View.h"
#include <memory>

class MenuDisplay : public View {
public:
  MenuDisplay(std::shared_ptr<MenuComponents> components);

  // Draw the menu
  virtual void draw() const override;

private:
  std::shared_ptr<MenuComponents> _components;
};

#endif // _FROGGER_MENUDISPAY_H
