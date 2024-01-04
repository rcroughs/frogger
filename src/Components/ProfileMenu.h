#ifndef _FROGGER_PROFILE_MENU_H_
#define _FROGGER_PROFILE_MENU_H_

#include "../Driver.h"
#include "Buttons/SaveButton.h"
#include "TextInput.h"
#include <FL/Fl.H>
#include <memory>

class ProfileMenu {
public:
  ProfileMenu(int x, int y, Driver *driver);
  Fl_PNG_Image *getImage();
  int getX();
  int getY();
  void changeVisibility();
  bool isVisible();
  std::shared_ptr<TextInput> getTextInput();
  std::shared_ptr<SaveButton> getSaveButton();
  std::string getCurrentNickname();

private:
  int _x;
  int _y;
  Driver *driver;
  bool _isVisible = false;
  std::shared_ptr<TextInput> textInput;
  std::shared_ptr<SaveButton> saveButton;
  std::string currentNickname;
  Fl_PNG_Image *image;
};

#endif // _FROGGER_PROFILE_MENU_H_