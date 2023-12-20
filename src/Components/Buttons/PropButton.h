#ifndef SRC_PROPBUTTON_H
#define SRC_PROPBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class PropButton : public Button {
public:
  PropButton(int x, int y, Driver *driver, short id);
  ~PropButton() { delete image; }
  virtual Fl_PNG_Image *getImage() override { return image; };
  virtual int getX() { return x; }
  virtual int getY() { return y; }
  virtual bool contains(int x, int y);
  virtual bool canMove() { return false; }
  virtual void onClick();
  virtual void resetPosition(){};
  virtual bool isMoving() { return false; }
  virtual void changeMovingState() {}
  virtual void changePosition(int loc_x, int loc_y) {
    x = loc_x;
    y = loc_y;
  }
  virtual bool isDisplayed() { return displayed; }
  virtual void changeState() { displayed = !displayed; }

private:
  Fl_PNG_Image *image;
  Driver *driver;
  int x;
  int y;
  short id; // 0, 1
  bool displayed{false};
};

#endif // SRC_PROPBUTTON_H
