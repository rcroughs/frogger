#include "LevelSelector.h"
#include "AddMapMenu.h"
#include "Buttons/MenuButton.h"
#include <dirent.h>
#include <FL/Fl.H>
#include <memory>
#include <vector>


LevelSelector::LevelSelector(Driver* driver) : _driver{driver} {
    _bg = new Fl_PNG_Image("res/bg.png");
    _menuButton = std::make_shared<MenuButton>(250, 600, _driver);
    _addMapMenu = std::make_shared<AddMapMenu>();
    std::vector<std::string> files = getFiles("maps");
    for (int i = 0; i < files.size(); i++) {
        _buttons.push_back(std::make_shared<LevelButton>(
            _driver, 100, (i * 250) + (50 * (i + 1)),"maps/" + files[i]));
    }
}

void LevelSelector::scrollUp() {
  if (_buttons[0]->getY() < 50) {
    for (auto button : _buttons) {
      button->changePosition(button->getX(), button->getY() + 50);
    }
  }
}

void LevelSelector::scrollDown() {
    if (_buttons[_buttons.size() - 1]->getY() > 350) {
        for (auto button : _buttons) {
            button->changePosition(button->getX(), button->getY() - 50);
        }
    }
}

std::vector<std::shared_ptr<LevelButton>> LevelSelector::getButtons() const {
    return _buttons;
}

std::shared_ptr<MenuButton> LevelSelector::getMenuButton() const {
    return _menuButton;
}

std::shared_ptr<AddMapMenu> LevelSelector::getAddMapMenu() const {
    return _addMapMenu;
}

Fl_PNG_Image *LevelSelector::getBg() const {
    return _bg;
}

std::vector<std::string> LevelSelector::getFiles(std::string path) {
    std::vector<std::string> files;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != nullptr) {
      while ((ent = readdir(dir)) != nullptr) {
        if (ent->d_name[0] != '.') {
          files.push_back(ent->d_name);
        }
      }
      closedir(dir);
    } else {
      perror("");
    }
    return files;
}