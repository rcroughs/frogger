#ifndef FROGGER_LILYPAD_H
#define FROGGER_LILYPAD_H

#include "../../Game.h"
#include "FL/Fl.H"
#include "Prop.h"
#include <FL/Fl_PNG_Image.H>

class LilyPad : public Prop {
public:
  LilyPad(float leftCornerPos);
  ~LilyPad() { delete image; }
  virtual float getPosition() override { return leftCorner; }
  virtual float getRightCorner() override { return leftCorner + size; }
  virtual Fl_Color getColor() override { return color; }
  virtual float getSize() override { return size; }
  virtual bool contains(float playerPosition) override {
    return getPosition() < playerPosition && playerPosition < getRightCorner();
  }
  virtual void move(){};
  virtual void handleGame(Game *currentGame);
  virtual bool hasImage() override { return true; };
  virtual Fl_PNG_Image *getImage() { return image; };
  bool isVisible() override { return true; }
  void update() override {};

private:
  Fl_PNG_Image *image;
  float leftCorner;
  float size{5};
  Fl_Color color{FL_GREEN};
  bool hasTurtle;

};

#endif // FROGGER_LILYPAD_H
