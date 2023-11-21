#include "../Environment.h"
#include "FL/Fl.H"

class SideWalk : public Environment {
private:
    Fl_Color color;

private:
    SideWalk() : color{FL_GRAY} {}
    Fl_Color getColor() {return color;}
    void setColor(Fl_Color new_color) {color = new_color;}
};
