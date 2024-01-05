#ifndef FROGGER_MENUDISPLAY_H
#define FROGGER_MENUDISPLAY_H

#include "../Components/MenuComponents.h"
#include "View.h"
#include <memory>

class MenuDisplay : public View {
public:
  MenuDisplay(std::shared_ptr<MenuComponents> components);
  virtual void draw() const override;

private:
  std::shared_ptr<MenuComponents> _components;
};

#endif // FROGGER_MENUDISPAY_H
