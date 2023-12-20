#ifndef FROGGER_PLAYBUTTON_H
#define FROGGER_PLAYBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"

class Driver;

class PlayButton : public Button {
public:
  PlayButton(int x, int y, Driver *driver);
  ~PlayButton() { delete image; }
  virtual Fl_PNG_Image *getImage() override { return image; };
  virtual int getX() { return x; }
  virtual int getY() { return y; }
  virtual bool contains(int x, int y);
  virtual bool canMove() { return false; }
  virtual void onClick();
  virtual void resetPosition(){};
  virtual bool isDisplayed() { return false; }
  virtual bool isMoving() { return false; }
  virtual void changeMovingState() {}
  virtual void changePosition(int loc_x, int loc_y) {
    x = loc_x;
    y = loc_y;
  }
  virtual void changeState() {}

private:
  Fl_PNG_Image *image;
  Driver *driver;
  int x;
  int y;
};

#endif // FROGGER_PLAYBUTTON_H
