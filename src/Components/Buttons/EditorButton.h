#ifndef FROGGER_EDITORBUTTON_H
#define FROGGER_EDITORBUTTON_H

#include "FL/Fl_PNG_Image.H"
#include "../Button.h"

class EditorButton : public Button{
private:
    Fl_PNG_Image* image;
    int x;
    int y;
public:
    EditorButton(int x, int y);
    ~EditorButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual bool contains(int x, int y);
    virtual void onClick();
};


#endif //FROGGER_EDITORBUTTON_H
