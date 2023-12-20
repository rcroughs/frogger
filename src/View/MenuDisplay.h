#ifndef FROGGER_MENUDISPLAY_H
#define FROGGER_MENUDISPLAY_H

#include "../Components/MenuComponents.h"
#include "View.h"
#include <memory>

class MenuDisplay : public View {
public:
  MenuDisplay(std::shared_ptr<MenuComponents> components)
      : _components{std::move(components)} {}
  void draw() override;

private:
  std::shared_ptr<MenuComponents> _components;
};

#endif // FROGGER_MENUDISPAY_H
