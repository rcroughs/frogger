#ifndef FROGGER_QUITBUTTON_H
#define FROGGER_QUITBUTTON_H

#include "../Button.h"

class QuitButton : public Button {
private:
    Fl_PNG_Image* image;
    int x;
    int y;
public:
    QuitButton(int x, int y);
    ~QuitButton() {
        delete image;
    }
    virtual Fl_PNG_Image* getImage() override {return image;};
    virtual int getX() {return x;}
    virtual int getY() {return y;}
    virtual bool contains(int x, int y) {};
    virtual void onClick();
};


#endif //FROGGER_QUITBUTTON_H
