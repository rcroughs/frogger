#ifndef SRC_SPEEDX1ROAD_H
#define SRC_SPEEDX1ROAD_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class SpeedButton : public Button {
public:
  SpeedButton(int x, int y, Driver* driver, short id);
  ~SpeedButton();

  // Getters
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual int getX() const override;
  [[nodiscard]] virtual int getY() const override;
  [[nodiscard]] virtual short getId() const;
  [[nodiscard]] virtual bool isDisplayed() const override;
  [[nodiscard]] virtual bool canMove() const override;
  [[nodiscard]] virtual bool isMoving() const override;
  [[nodiscard]] virtual bool contains(int x, int y) const override;

  // onClick event
  virtual void onClick() override;

  // Setters
  virtual void resetPosition() override;
  virtual void changePosition(int loc_x, int loc_y) override;
  virtual void changeMovingState() override;
  virtual void changeState() override;

private:
  Fl_PNG_Image *_image;
  Driver* _driver;
  int _x;
  int _y;
  short _id; // 0, 1 or 2
  bool _displayed{false};

};

#endif // SRC_SPEEDX1ROAD_H
