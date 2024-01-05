#include "MenuComponents.h"
#include "Buttons/EditorButton.h"
#include "Buttons/PlayButton.h"
#include "Buttons/QuitButton.h"
#include "Fl/Fl_PNG_Image.H"
#include <memory>

MenuComponents::MenuComponents(Driver *driver) : _driver{driver} {
  _logo = new Fl_PNG_Image("res/title.png");
  _bg = new Fl_PNG_Image("res/bg.png");
  _clouds.push_back(std::make_shared<Cloud>(0, false));
  _clouds.push_back(std::make_shared<Cloud>(150, true));
  _buttons.push_back(std::make_shared<PlayButton>(250, 300, driver));
  _buttons.push_back(std::make_shared<EditorButton>(250, 420, driver));
  _buttons.push_back(std::make_shared<QuitButton>(250, 540));
}

MenuComponents::~MenuComponents() {
  delete _logo;
  delete _bg;
}

Fl_PNG_Image *MenuComponents::getLogo() const { return _logo; }

Fl_PNG_Image *MenuComponents::getBackground() const { return _bg; }

std::vector<std::shared_ptr<Button>> MenuComponents::getButtons() const {
  return _buttons;
}

std::vector<std::shared_ptr<Cloud>> MenuComponents::getClouds() const { return _clouds; };

void MenuComponents::update() {
  for (auto &cloud : _clouds) {
    cloud->update();
  }
}