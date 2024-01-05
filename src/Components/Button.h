#ifndef FROGGER_BUTTONS_H
#define FROGGER_BUTTONS_H

#include <FL/Fl_PNG_Image.H>
#include <string>

class Button {
public:
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const = 0;
  [[nodiscard]] virtual int getX() const = 0;
  [[nodiscard]] virtual int getY() const = 0;
  [[nodiscard]] virtual bool contains(int x, int y) const = 0;
  [[nodiscard]] virtual bool canMove() const = 0;
  [[nodiscard]] virtual bool isDisplayed() const = 0;
  [[nodiscard]] virtual bool isMoving() const = 0;
  virtual void onClick() = 0;
  virtual void resetPosition() = 0;
  virtual void changeMovingState() = 0;
  virtual void changeState() = 0;
  virtual void changePosition(int loc_x, int loc_y) = 0;
};

#endif // FROGGER_BUTTONS_H
