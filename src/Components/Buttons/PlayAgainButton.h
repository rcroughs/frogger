#ifndef _FROGGER_PLAYAGAINBUTTON_H_
#define _FROGGER_PLAYAGAINBUTTON_H_


#include "../../Driver.h"
#include "../Button.h"
#include <memory>

class PlayAgainButton : public Button {
public:
  PlayAgainButton(int x, int y, Driver *driver);
  ~PlayAgainButton();

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

private:
  Fl_PNG_Image *_image;
  Driver *_driver;
  int _x;
  int _y;
};

#endif // _FROGGER_PLAYAGAINBUTTON_H_
