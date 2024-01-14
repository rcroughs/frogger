#ifndef FROGGER_CONTROLLER_H
#define FROGGER_CONTROLLER_H

class Controller {
public:

  // Event when mouse is moved
  // Args are the x and y location of the mouse
  virtual void mouseMove(short loc_x, short loc_y) = 0;

  // Event when mouse is clicked
  // args are the x and y location of the mouse
  virtual void mouseClick(short loc_x, short loc_y) = 0;

  // Event when mouse is released
  // args are the x and y location of the mouse
  virtual void mouseRelease(short loc_x, short loc_y) = 0;

  // Event when a key is pressed
  // keycode is the code of the key that was pressed
  virtual void keyPressed(int keycode) = 0;

  // Event when a key is released
  // keycode is the code of the key that was released
  virtual void keyReleased(int keycode) = 0;

  // Event when the game should update movement
  virtual void updateMovement() = 0;
};

#endif // FROGGER_CONTROLLER_H
