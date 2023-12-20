#ifndef FROGGER_CONTROLLER_H
#define FROGGER_CONTROLLER_H

class Controller {
public:
  virtual void mouseMove(short loc_x, short loc_y) = 0;
  virtual void mouseClick(short loc_x, short loc_y) = 0;
  virtual void mouseRelease(short loc_x, short loc_y) = 0;
  virtual void keyPressed(int keycode) = 0;
  virtual void keyReleased(int keycode) = 0;
  virtual void updateMovement() = 0;
};

#endif // FROGGER_CONTROLLER_H
