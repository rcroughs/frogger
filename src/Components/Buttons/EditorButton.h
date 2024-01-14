#ifndef FROGGER_EDITORBUTTON_H
#define FROGGER_EDITORBUTTON_H

#include "../Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>

class Driver;

class EditorButton : public Button {
public:
  EditorButton(int x, int y, Driver *driver);
  ~EditorButton();

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
};

#endif // FROGGER_EDITORBUTTON_H
