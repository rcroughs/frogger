#include "Prop.h"
#include "../../Position.h"
#include "FL/Fl.H"

class Log : public Prop {
private:
    float size;
    float center;
    Fl_Color color;
public:
    Log(float initPosition) : size{15}, center{initPosition}, color{FL_RED} {};

    virtual float getPosition() override {return center;}
    virtual Fl_Color getColor() override {return color;}
    virtual bool contains(float playerPosition) override;
    virtual void moveRight() override;
    virtual void moveLeft() override;
};
