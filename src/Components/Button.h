#ifndef FROGGER_BUTTONS_H
#define FROGGER_BUTTONS_H

#include <FL/Fl_PNG_Image.H>
#include <string>

class Button {
public:
  virtual Fl_PNG_Image *getImage() = 0;
  virtual int getX() = 0;
  virtual int getY() = 0;
  virtual bool contains(int x, int y) = 0;
  virtual bool canMove() = 0;
  virtual void onClick() = 0;
  virtual void resetPosition() = 0;
  virtual bool isDisplayed() = 0;
  virtual bool isMoving() = 0;
  virtual void changeMovingState() = 0;
  virtual void changeState() = 0;
  virtual void changePosition(int loc_x, int loc_y) = 0;
};

#endif // FROGGER_BUTTONS_H
