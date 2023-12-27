#include "LevelButton.h"
#include "../../Driver.h"
#include <fstream>
#include <string>

LevelButton::LevelButton(Driver* driver, int x, int y, std::string levelPath, bool canMove) : _driver{driver}, _x{x}, _y{y}, _levelPath{levelPath}, _canMove{canMove}
{
    _image = new Fl_PNG_Image("res/level.png");
    std::ifstream inputFile(levelPath);
    std::string mapName, mapAuthor;
    std::getline(inputFile, mapName);
    std::getline(inputFile, mapAuthor);
    levelName = mapName;
    authorName = mapAuthor;
    inputFile.close();
    _isDisplayed = true;
    _isMoving = false;
}

LevelButton::~LevelButton() {
    delete _image;
}

bool LevelButton::contains(int x, int y) {
    if (_x < x && x < _x + 500 && y < _y + 250 && _y < y)
        return true;
    return false;
}

void LevelButton::onClick() {
    _driver->LaunchGameFromFile(_levelPath);
}
