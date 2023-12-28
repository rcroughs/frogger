#include "AddMapButton.h"
#include <fstream>
#include <memory>

AddMapButton::AddMapButton(int x, int y, std::shared_ptr<TextInput> mapName,
                           std::shared_ptr<TextInput> authorName,
                           std::shared_ptr<TextInput> mapId)
    : _mapNameInput{std::move(mapName)}, _mapAuthorInput{std::move(authorName)},
      _mapIdInput(std::move(mapId)), _x{x}, _y{y} {
  image = new Fl_PNG_Image("res/add.png");
}

AddMapButton::~AddMapButton() {
    delete image;
}

Fl_PNG_Image *AddMapButton::getImage() {
    return image;
}

int AddMapButton::getX() {
    return _x;
}

int AddMapButton::getY() {
    return _y;
}

bool AddMapButton::contains(int x, int y) {
    if (x >= _x && x <= _x + 250 && y >= _y && y <= _y + 100) {
        return true;
    }
    return false;
}

bool AddMapButton::canMove() {
    return false;
}

void AddMapButton::resetPosition() {
    return;
}

bool AddMapButton::isDisplayed() {
    return true;
}

bool AddMapButton::isMoving() {
    return false;
}

void AddMapButton::changeMovingState() {
    return;
}

void AddMapButton::changeState() {
    return;
} 

void AddMapButton::onClick() {
    std::ofstream mapFile;
    mapFile.open("maps/" + _mapNameInput->getInput() + ".map");
    mapFile << _mapNameInput->getInput() << std::endl;
    mapFile << _mapAuthorInput->getInput() << std::endl;
    mapFile << _mapIdInput->getInput() << std::endl;
    mapFile.close();
}

void AddMapButton::changePosition(int loc_x, int loc_y) {
    _x = loc_x;
    _y = loc_y;
}