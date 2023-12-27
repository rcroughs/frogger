#ifndef _FROGGER_LEVEL_BUTTON_H_
#define _FROGGER_LEVEL_BUTTON_H_

#include "../Button.h"
#include "../../Driver.h"

class Driver;

class LevelButton : public Button {
public:
  LevelButton(Driver* driver, int x, int y, std::string levelPath, bool canMove = false);
  ~LevelButton();

  Fl_PNG_Image *getImage() override {return _image;}
  int getX() override { return _x; } 
  int getY() override {return _y; } 
  bool contains(int x, int y) override;
  bool canMove() override { return _canMove; }
  void onClick() override;
  void resetPosition() override { _x = 0; _y = 0; }
  bool isDisplayed() override { return _isDisplayed; }
  bool isMoving() override { return _isMoving; }
  void changeMovingState() override { _isMoving = _canMove ? !_isMoving : _isMoving; }
  void changeState() override { _isDisplayed = !_isDisplayed; }
  void changePosition(int loc_x, int loc_y) override { _x = loc_x; _y = loc_y; }
  std::string getName() { return levelName; }
  std::string getAuthor() { return authorName; }

private:
    Driver* _driver;
    Fl_PNG_Image *_image;
    std::string _levelPath;
    std::string levelName;
    std::string authorName;
    std::string highestScore;
    int _x;
    int _y;
    bool _isDisplayed;
    bool _isMoving;
    bool _canMove;
};

#endif // _FROGGER_LEVEL_BUTTON_H_