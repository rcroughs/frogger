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

  [[nodiscard]] virtual std::vector<std::shared_ptr<Button>> getButtons() const;
  // virtual void updatePosition(Position mouseloc) {};

private:
  std::vector<std::shared_ptr<Button>> _buttons;
  Driver* _driver;
};

#endif // SRC_EDITORMENU_H
