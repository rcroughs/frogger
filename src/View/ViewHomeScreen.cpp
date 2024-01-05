#include "ViewHomeScreen.h"
#include <memory>

ViewHomeScreen::ViewHomeScreen() {
  _image = std::make_shared<Fl_PNG_Image>("res/homescreen.png");
}

void ViewHomeScreen::draw() const { _image->draw(0, 0); }