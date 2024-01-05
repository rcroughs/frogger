#ifndef SRC_RIGHTBUTTON_H
#define SRC_RIGHTBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class DirectionButton : public Button {
public:
  DirectionButton(int x, int y, Driver *driver, short id);
  ~DirectionButton();
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual int getX() const override;
  [[nodiscard]] virtual int getY() const override;
  [[nodiscard]] virtual bool isDisplayed() const override;
  [[nodiscard]] virtual bool canMove() const override;
  [[nodiscard]] virtual bool isMoving() const override;
  [[nodiscard]] virtual bool contains(int x, int y) const override;
  virtual void onClick() override;
  virtual void resetPosition() override;
  virtual void changeMovingState() override;
  virtual void changePosition(int loc_x, int loc_y) override;
  virtual void changeState() override;

  virtual short getId() const;

private:
  Fl_PNG_Image *_image;
  Driver *_driver;
  int _x;
  int _y;
  short _id; // 0, 1
  bool _displayed{false};
};

#endif // SRC_RIGHTBUTTON_H
