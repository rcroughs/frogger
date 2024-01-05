#include "MenuDisplay.h"
#include "../Components/Button.h"
#include "../Components/Cloud.h"
#include <memory>
#include <vector>

MenuDisplay::MenuDisplay(std::shared_ptr<MenuComponents> components)
    : _components{std::move(components)} {}

void MenuDisplay::draw() const {
  _components->getBackground()->draw(0, 0);
  _components->getLogo()->draw(150, 100);
  std::vector<std::shared_ptr<Cloud>> clouds = _components->getClouds();
  for (auto &cloud : clouds) {
    cloud->getImage()->draw(cloud->getX(), cloud->getY());
    cloud->update();
  }
  std::vector<std::shared_ptr<Button>> buttons = _components->getButtons();
  for (auto &button : buttons) {
    button->getImage()->draw(button->getX(), button->getY());
  }
}