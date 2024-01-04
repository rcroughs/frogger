#ifndef _FROGGER_PROFILE_BUTTON_H_
#define _FROGGER_PROFILE_BUTTON_H_

#include "../Button.h"
#include "../MenuComponents.h"

class ProfileButton : public Button {
public:
  ProfileButton(int x, int y, MenuComponents* MenuComponents);
  ~ProfileButton();
  Fl_PNG_Image *getImage();
  int getX();
  int getY();
  bool contains(int x, int y);
  bool canMove();
  void onClick();
  void resetPosition();
  bool isDisplayed();
  bool isMoving();
  void changeMovingState();
  void changeState();
  void changePosition(int loc_x, int loc_y);

private:
    Fl_PNG_Image *image;
    MenuComponents* menuComponents;
    int _x;
    int _y;
};

#endif // _FROGGER_PROFILE_BUTTON_H_