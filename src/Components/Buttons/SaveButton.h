#ifndef _FROGGER_SAVE_BUTTON_H_
#define _FROGGER_SAVE_BUTTON_H_

#include "../Button.h"
#include "../../Driver.h"
#include <memory>

class SaveButton : public Button {
public:
    SaveButton(int x, int y, Driver* MenuComponents, std::shared_ptr<TextInput> textInput);
    ~SaveButton();
    Fl_PNG_Image *getImage();
    int getX();
    int getY();
    bool contains(int x, int y);
    bool canMove();
    void onClick();
    void resetPosition();
    bool isDisplayed();
    bool isMoving();
    void changeMovingState();
    void changeState();
    void changePosition(int loc_x, int loc_y);

private:
    Fl_PNG_Image *image;
    Driver* driver;
    int _x;
    int _y;
    std::shared_ptr<TextInput> _textInput;
};


#endif // _FROGGER_SAVE_BUTTON_H_