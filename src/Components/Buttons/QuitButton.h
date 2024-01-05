#ifndef FROGGER_QUITBUTTON_H
#define FROGGER_QUITBUTTON_H

#include "../Button.h"

class QuitButton : public Button {
public:
  QuitButton(int x, int y);
  ~QuitButton();

  [[nodiscard]] virtual int getX() const override;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
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
  int _x;
  int _y;
};

#endif // FROGGER_QUITBUTTON_H
