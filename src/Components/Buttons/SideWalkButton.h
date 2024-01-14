#ifndef SRC_SIDEWALKBUTTON_H
#define SRC_SIDEWALKBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class SideWalkButton : public Button {
public:
  SideWalkButton(int x, int y, Driver *driver);
  ~SideWalkButton();

  // Getters
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual int getX() const override;
  [[nodiscard]] virtual int getY() const override;
  [[nodiscard]] virtual bool isDisplayed() const override;
  [[nodiscard]] virtual bool canMove() const override;
  [[nodiscard]] virtual bool isMoving() const override;
  [[nodiscard]] virtual bool contains(int x, int y) const override;

  // onClick event
  virtual void onClick() override;

  // Setters
  virtual void resetPosition() override;
  virtual void changeMovingState() override;
  virtual void changeState() override;
  virtual void changePosition(int loc_x, int loc_y) override;

private:
  Fl_PNG_Image *_image;
  Driver *_driver;
  int _x;
  int _y;
  bool _displayed{true};
  bool _moving{false};
};

#endif // SRC_SIDEWALKBUTTON_H
