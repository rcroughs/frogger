#ifndef _FROGGER_LEVEL_BUTTON_H_
#define _FROGGER_LEVEL_BUTTON_H_

#include "../Button.h"
#include "../../Driver.h"

class Driver;

class LevelButton : public Button {
public:
  LevelButton(Driver* driver, int x, int y, std::string levelPath, bool canMove = false);
  ~LevelButton();

  // Getters 
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual int getX() const override;
  [[nodiscard]] virtual int getY() const override;
  [[nodiscard]] virtual bool isDisplayed() const override;
  [[nodiscard]] virtual bool canMove() const override;
  [[nodiscard]] virtual bool isMoving() const override;
  [[nodiscard]] virtual bool contains(int x, int y) const override;
  [[nodiscard]] virtual std::string getName() const;
  [[nodiscard]] virtual std::string getAuthor() const;
  [[nodiscard]] virtual std::string getHighestScore() const;

  // onClick event
  virtual void onClick() override;

  // Setters
  virtual void resetPosition() override;
  virtual void changeMovingState() override;
  virtual void changePosition(int loc_x, int loc_y) override;
  virtual void changeState() override;

private:
    Driver* _driver;
    Fl_PNG_Image *_image;
    std::string _levelPath;
    std::string _levelName;
    std::string _authorName;
    std::string _highestScore;
    int _x;
    int _y;
    bool _isDisplayed;
    bool _isMoving;
    bool _canMove;
};

#endif // _FROGGER_LEVEL_BUTTON_H_