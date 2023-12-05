#ifndef FROGGER_TURTLE_H
#define FROGGER_TURTLE_H

#include "FL/Fl.H"
#include "Prop.h"
#include "../../Game.h"
#include "Fl/Fl_PNG_Image.H"
#include "iostream"

class Turtle : public Prop {
private:
    float position;
    float size;
    Fl_Color color;
    Fl_PNG_Image* img;
public:
    Turtle(float position, short turtleNumber) : position{position}, color{FL_GREEN} {
        if (turtleNumber == 2) {
            img = new Fl_PNG_Image("../res/two_turtles.png");
            if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                std::cout << "Image couln't load";
            }
            size = 15.0f;
        } else if (turtleNumber == 3) {
            img = new Fl_PNG_Image("../res/three_turtles.png");
            if (img->fail() == Fl_Image::ERR_FILE_ACCESS) {
                std::cout << "Image couln't load";
            }
            size = 22.0f;
        }
    }
    ~Turtle() {
        delete img;
    }
    virtual float getPosition() override {return position;}
    virtual float getRightCorner() override {return position + size;}
    virtual Fl_Color getColor() override {return color;}
    virtual float getSize() override {return size;}
    virtual bool contains(float playerPosition) override;
    virtual void move() override;
    virtual void handleGame(Game* currentGame) override;
    virtual bool hasImage() override {return true;}
    virtual Fl_PNG_Image* getImage() {return img;};
};


#endif //FROGGER_TURTLE_H
