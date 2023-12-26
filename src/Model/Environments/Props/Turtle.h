#ifndef FROGGER_TURTLE_H
#define FROGGER_TURTLE_H

#include "../../Game.h"
#include "FL/Fl.H"
#include "Fl/Fl_PNG_Image.H"
#include "Prop.h"
#include "iostream"
#include <string>

class Turtle : public Prop {
public:
  Turtle(float position, short turtleNumber)
      : position{position}, color{FL_GREEN}, visible{true}, invisibleTimer{0}, turtleNumber{turtleNumber} {
    if (turtleNumber == 2) {
      img = new Fl_PNG_Image("res/two_turtles.png");
      if (img->fail() == Fl_Image::ERR_NO_IMAGE) {
        std::cout << "Image couln't load";
      }
      size = 15.0f;
    } else if (turtleNumber == 3) {
      img = new Fl_PNG_Image("res/three_turtles.png");
      if (img->fail() == Fl_Image::ERR_FILE_ACCESS) {
        std::cout << "Image couln't load";
      }
      size = 22.0f;
    }
  }
  ~Turtle() { delete img; }
  virtual float getPosition() override { return position; }
  virtual float getRightCorner() override { return position + size; }
  virtual Fl_Color getColor() override { return color; }
  virtual float getSize() override { return size; }
  virtual bool contains(float playerPosition) override;
  virtual void move() override;
  virtual void handleGame(Game *currentGame) override;
  virtual bool hasImage() override { return true; }
  virtual Fl_PNG_Image *getImage() { return img; }
  bool isVisible() override { return visible; }
  void update() override;

private:
  float position;
  float size;
  short turtleNumber;
  Fl_Color color;
  Fl_PNG_Image *img;
  bool visible;
  unsigned int invisibleTimer;
};

#endif // FROGGER_TURTLE_H
