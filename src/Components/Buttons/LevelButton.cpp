#include "LevelButton.h"
#include "../../Driver.h"
#include <fstream>
#include <string>

LevelButton::LevelButton(Driver* driver, int x, int y, std::string levelPath, bool canMove) : _driver{driver}, _levelPath{levelPath}, _x{x}, _y{y}, _canMove{canMove}
{
    _image = new Fl_PNG_Image("res/level.png");
    std::ifstream inputFile(levelPath);
    std::string mapName, mapAuthor;
    std::getline(inputFile, mapName);
    std::getline(inputFile, mapAuthor);
    _levelName = mapName;
    _authorName = mapAuthor;
    inputFile.close();
    _isDisplayed = true;
    _isMoving = false;
}

LevelButton::~LevelButton() {
    delete _image;
}

Fl_PNG_Image *LevelButton::getImage() const {
    return _image;
}

int LevelButton::getX() const {
    return _x;
}

int LevelButton::getY() const {
    return _y;
}

bool LevelButton::isDisplayed() const {
    return _isDisplayed;
}

bool LevelButton::canMove() const {
    return _canMove;
}

bool LevelButton::isMoving() const {
    return _isMoving;
}

bool LevelButton::contains(int x, int y)  const {
    if (_x < x && x < _x + 500 && y < _y + 250 && _y < y)
        return true;
    return false;
}

void LevelButton::onClick() {
    _driver->LaunchGameFromFile(_levelPath);
}

void LevelButton::resetPosition() {
    return;
}

void LevelButton::changeMovingState() {
    _isMoving = !_isMoving;
}

void LevelButton::changePosition(int loc_x, int loc_y) {
    _x = loc_x;
    _y = loc_y;
}

void LevelButton::changeState() {
    _isDisplayed = !_isDisplayed;
}

std::string LevelButton::getName() const {
    return _levelName;
}

std::string LevelButton::getAuthor() const {
    return _authorName;
}


