#ifndef SRC_ROADBUTTON_H
#define SRC_ROADBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class RoadButton : public Button {
public:
  RoadButton(int x, int y, Driver *driver);
  ~RoadButton() { delete image; }
  virtual Fl_PNG_Image *getImage() override { return image; };
  virtual int getX() { return x; }
  virtual int getY() { return y; }
  virtual bool contains(int x, int y);
  virtual void onClick();
  virtual void resetPosition() { changePosition((700 / 2) - 23, 700); }
  virtual bool isDisplayed() { return displayed; }
  virtual bool canMove() { return true; }
  virtual bool isMoving() { return moving; }
  virtual void changeMovingState() { moving = !moving; }
  virtual void changeState() { displayed = !displayed; }
  virtual void changePosition(int loc_x, int loc_y) {
    x = loc_x;
    y = loc_y;
  }

private:
  Fl_PNG_Image *image;
  Driver *driver;
  int x;
  int y;
  bool displayed{true};
  bool moving{false};
};

#endif // SRC_ROADBUTTON_H
