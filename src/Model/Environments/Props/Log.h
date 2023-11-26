#include "Prop.h"
#include "../../Position.h"
#include "FL/Fl.H"

class Log : public Prop {
private:
    float size;
    float leftCorner;
    Fl_Color color;
public:
    Log(float initPosition) : size{15}, leftCorner{initPosition}, color{FL_RED} {};

    virtual float getPosition() override {return leftCorner;}
    virtual Fl_Color getColor() override {return color;}
    virtual float getSize() override {return size;}
    virtual bool contains(float playerPosition) override;
    virtual void moveRight() override;
    virtual void moveLeft() override;
};
