#include "Prop.h"
#include "../../Position.h"
#include "FL/Fl.H"

class Log : public Prop {
private:
    float size;
    float leftCorner;
    float speed;
    Fl_Color color;
public:
    Log(float size, float initPosition, float speed) : size{size}, leftCorner{initPosition}, speed{speed}, color{fl_rgb_color(150, 75, 0)} {};

    virtual float getPosition() override {return leftCorner;}
    virtual float getRightCorner() override {return leftCorner + size;}
    virtual Fl_Color getColor() override {return color;}
    virtual float getSize() override {return size;}
    virtual bool contains(float playerPosition) override;
    virtual void moveRight() override;
    virtual void moveLeft() override;
};
