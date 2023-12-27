#ifndef _FROGGER_LEVEL_CONTROLLER_H_
#define _FROGGER_LEVEL_CONTROLLER_H_

#include "Controller.h"
#include "../Components/LevelSelector.h"

class LevelController : public Controller {
public:
  LevelController(std::shared_ptr<LevelSelector> levelSelector)
      : _levelSelector{std::move(levelSelector)} {}
  void mouseMove(short loc_x, short loc_y);
  void mouseClick(short loc_x, short loc_y);
  void mouseRelease(short loc_x, short loc_y);
  void keyPressed(int keycode);
  void keyReleased(int keycode);
  void updateMovement();

private:
  std::shared_ptr<LevelSelector> _levelSelector;
};

#endif // _FROGGER_LEVEL_CONTROLLER_H_