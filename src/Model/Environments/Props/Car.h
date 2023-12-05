#ifndef SRC_CAR_H
#define SRC_CAR_H

#include "Prop.h"
#include "../../Position.h"
#include "../../Game.h"
#include "FL/Fl.H"
#include "iostream"

class Car : public Prop {
private:
    float size;
    float leftCorner;
    Fl_Color color;
    Fl_PNG_Image* img;
    char direction;
    float speed;
public:
    Car(float initPosition, short colorId, char direction, float speed) : leftCorner{initPosition}, direction{direction}, size{13.0f},
    color{FL_RED}, speed{speed} {
        if (colorId == 0) {
            if (direction == 'l') {
                img = new Fl_PNG_Image("../res/red_car_left.png");
                if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                    std::cout << "Image couln't load";
                }
            } else {
                img = new Fl_PNG_Image("../res/red_car_right.png");
                if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                    std::cout << "Image couln't load";
                }
            }
        }
        else if (colorId == 1) {
            if (direction == 'l') {
                img = new Fl_PNG_Image("../res/blue_car_left.png");
                if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                    std::cout << "Image couln't load";
                }
            } else {
                img = new Fl_PNG_Image("../res/blue_car_right.png");
                if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                    std::cout << "Image couln't load";
                }
            }
        }
        else {
            if (direction == 'l') {
                img = new Fl_PNG_Image("../res/green_car_left.png");
                if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                    std::cout << "Image couln't load";
                }
            } else {
                img = new Fl_PNG_Image("../res/green_car_right.png");
                if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
                    std::cout << "Image couln't load";
                }
            }
        }
    };
    ~Car() {
        delete img;
    }

    virtual float getPosition() override {return leftCorner;}
    virtual float getRightCorner() override {return leftCorner + size;}
    virtual float getSize() override {return size;}
    virtual Fl_Color getColor() override {return color;}
    virtual bool contains(float playerPosition) override;
    virtual void move() override;
    virtual void handleGame(Game* currentGame) override;
    virtual bool hasImage() override {return true;}
    virtual Fl_PNG_Image* getImage() {return img;};
};


#endif //SRC_CAR_H
