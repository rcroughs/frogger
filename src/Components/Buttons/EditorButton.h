#ifndef FROGGER_EDITORBUTTON_H
#define FROGGER_EDITORBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class EditorButton : public Button {
public:
  EditorButton(int x, int y, Driver *driver);
  ~EditorButton() { delete image; }
  Fl_PNG_Image *getImage() override { return image; };
  int getX() override { return x; }
  int getY() override { return y; }
  bool contains(int x, int y) override;
  bool canMove() override { return false; }
  void onClick() override;
  void resetPosition() override {};
  bool isDisplayed() override { return false; }
  bool isMoving() override { return false; }
  void changeMovingState() override {}
  void changePosition(int loc_x, int loc_y) override {
    x = loc_x;
    y = loc_y;
  }
  void changeState() override {};

private:
  Fl_PNG_Image *image;
  Driver *driver;
  int x;
  int y;
};

#endif // FROGGER_EDITORBUTTON_H
