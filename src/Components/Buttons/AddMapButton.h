#ifndef _FROGGER_ADD_MAP_BUTTON_H_
#define _FROGGER_ADD_MAP_BUTTON_H_

#include "../Button.h"
#include "../TextInput.h"
#include <memory>
#include <vector>
#include <FL/Fl_PNG_Image.H>

class AddMapButton : public Button {
public:
    AddMapButton(int x, int y, std::shared_ptr<TextInput> mapName,
                           std::shared_ptr<TextInput> authorName,
                           std::shared_ptr<TextInput> mapId);
    ~AddMapButton();
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
    std::shared_ptr<TextInput> _mapNameInput;
    std::shared_ptr<TextInput> _mapAuthorInput;
    std::shared_ptr<TextInput> _mapIdInput;
    int _x;
    int _y;
};

#endif // _FROGGER_ADD_MAP_BUTTON_H_