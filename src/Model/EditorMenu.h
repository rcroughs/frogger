////////// Editor Menu Header File - src/Model/EditorMenu.h //////////
// Description: This class represents the editor menu.
// Constructor takes: A pointer to the driver.
////////// FROGGER ////////////////////////////////////////

#ifndef _FROGGER_EDITORMENU_H
#define _FROGGER_EDITORMENU_H

#include "../Components/Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>
#include <vector>

// Forward declaration
class Driver;

class EditorMenu {
public:
  EditorMenu(Driver* driver);

  // Getter
  [[nodiscard]] virtual std::vector<std::shared_ptr<Button>> getButtons() const;
  // virtual void updatePosition(Position mouseloc) {};

private:
  std::vector<std::shared_ptr<Button>> _buttons;
  Driver* _driver;
};

#endif // _FROGGER_EDITORMENU_H
