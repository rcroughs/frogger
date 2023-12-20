#ifndef FROGGER_QUITBUTTON_H
#define FROGGER_QUITBUTTON_H

#include "../Button.h"

class QuitButton : public Button {
public:
  QuitButton(int x, int y);
  ~QuitButton() { delete image; }
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
  int x;
  int y;
};

#endif // FROGGER_QUITBUTTON_H
