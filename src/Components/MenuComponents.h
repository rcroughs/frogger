#ifndef FROGGER_MENUCOMPONENTS_H
#define FROGGER_MENUCOMPONENTS_H

#include "../Driver.h"
#include "Button.h"
#include "Cloud.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>
#include <vector>

class Driver;

class MenuComponents {
public:
  MenuComponents(Driver *driver);
  ~MenuComponents();
  [[nodiscard]] virtual Fl_PNG_Image *getLogo() const;
  [[nodiscard]] virtual Fl_PNG_Image *getBackground() const;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Button>> getButtons() const;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Cloud>> getClouds() const;

  void update();

private:
  Fl_PNG_Image *_logo;
  Fl_PNG_Image *_bg;
  std::vector<std::shared_ptr<Cloud>> _clouds;
  std::vector<std::shared_ptr<Button>> _buttons;
  Driver *_driver;
};

#endif //FROGGER_MENUCOMPONENTS_H
