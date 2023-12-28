#ifndef _FROGGER_PASTE_BUTTON_H_
#define _FROGGER_PASTE_BUTTON_H_

#include "../../Driver.h"
#include "../Button.h"
#include <FL/Fl_PNG_Image.H>
#include <future>
#include <memory>

class PasteButton : public Button {
public:
  PasteButton(std::shared_ptr<TextInput> textInput, int x, int y);
  ~PasteButton();
  Fl_PNG_Image *getImage() override;
  void onClick() override;
  int getX() override;
  int getY() override;
  bool contains(int x, int y) override;
  bool canMove() override;
  void resetPosition() override;
  bool isDisplayed() override;
  bool isMoving() override;
  void changeMovingState() override;
  void changeState() override;
  void changePosition(int loc_x, int loc_y) override;

private:
    Fl_PNG_Image *image;
    std::shared_ptr<TextInput> _textInput;
    int _x;
    int _y;
};

#endif // _FROGGER_PASTE_BUTTON_H_