#ifndef SRC_PROPBUTTON_H
#define SRC_PROPBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class PropButton : public Button {
public:
  PropButton(int x, int y, Driver *driver, short id);
  ~PropButton();

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
  virtual void changePosition(int loc_x, int loc_y) override;
  virtual void changeState() override;

private:
  Fl_PNG_Image *_image;
  Driver *_driver;
  int _x;
  int _y;
  short _id; // 0, 1
  bool _displayed{false};
};

#endif // SRC_PROPBUTTON_H
