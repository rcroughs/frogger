#ifndef FROGGER_MENUCONTROLLER_H
#define FROGGER_MENUCONTROLLER_H

#include "../Components/MenuComponents.h"
#include "Controller.h"
#include <memory>

class MenuController : public Controller {
public:
  MenuController(std::shared_ptr<MenuComponents>menu);
  ~MenuController() = default;

  virtual void mouseMove(short loc_x, short loc_y) override;
  virtual void mouseClick(short loc_x, short loc_y) override;
  virtual void mouseRelease(short loc_x, short loc_y) override;
  virtual void keyPressed(int keycode) override;
  virtual void keyReleased(int keycode) override;
  virtual void updateMovement() override;

private:
  std::shared_ptr<MenuComponents> _menu;
};

#endif // FROGGER_MENUCONTROLLER_H
