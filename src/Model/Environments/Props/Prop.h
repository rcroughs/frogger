#ifndef FROGGER_PROP_H
#define FROGGER_PROP_H

#include "FL/Fl.H"


class Prop {
public:
    virtual float getPosition() =0;
    virtual Fl_Color getColor() =0;
    virtual bool contains(float playerPosition) =0;
    virtual void moveRight() =0;
    virtual void moveLeft() =0;
};


#endif //FROGGER_PROP_H
