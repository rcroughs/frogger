#include "ProfileMenu.h"
#include <FL/Fl.H>

ProfileMenu::ProfileMenu(int x, int y, Driver *driver)
    : _x{x}, _y{y}, driver{driver}, currentNickname{driver->getNickname()} {
  Fl_PNG_Image *image = new Fl_PNG_Image("res/profilemenu.png");
  textInput = std::make_shared<TextInput>(_x, _y, "Change your nickname");
  saveButton =
      std::make_shared<SaveButton>(_x + 50, _y + 150, driver, textInput);
}

int ProfileMenu::getX() { return _x; }

int ProfileMenu::getY() { return _y; }

void ProfileMenu::changeVisibility() { _isVisible = !_isVisible; }

bool ProfileMenu::isVisible() { return _isVisible; }

std::shared_ptr<TextInput> ProfileMenu::getTextInput() { return textInput; }

std::shared_ptr<SaveButton> ProfileMenu::getSaveButton() { return saveButton; }

std::string ProfileMenu::getCurrentNickname() { return currentNickname; }

Fl_PNG_Image *ProfileMenu::getImage() { return image; }
