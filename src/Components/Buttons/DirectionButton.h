#ifndef SRC_RIGHTBUTTON_H
#define SRC_RIGHTBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class DirectionButton : public Button {
public:
  DirectionButton(int x, int y, Driver *driver, short id);
  ~DirectionButton() { delete image; }
  virtual Fl_PNG_Image *getImage() override { return image; };
  virtual int getX() { return x; }
  virtual int getY() { return y; }
  virtual bool contains(int x, int y);
  virtual void onClick();
  virtual void resetPosition(){};
  virtual bool isDisplayed() { return displayed; }
  virtual bool canMove() { return false; }
  virtual bool isMoving() { return false; }
  virtual void changeMovingState() {}
  virtual void changePosition(int loc_x, int loc_y) {
    x = loc_x;
    y = loc_y;
  }
  virtual void changeState() { displayed = !displayed; }

  virtual short getId() { return id; }

private:
  Fl_PNG_Image *image;
  Driver *driver;
  int x;
  int y;
  short id; // 0, 1
  bool displayed{false};
};

#endif // SRC_RIGHTBUTTON_H
