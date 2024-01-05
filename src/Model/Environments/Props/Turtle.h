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
  Turtle(float position, short turtleNumber);
  ~Turtle();
  [[nodiscard]] virtual float getPosition() const override;
  [[nodiscard]] virtual float getRightCorner() const override;
  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual float getSize() const override;
  [[nodiscard]] virtual bool contains(float playerPosition) const override;
  virtual void move() override;
  virtual void handleGame(Game *currentGame) override;
  [[nodiscard]] virtual bool hasImage() const override;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] bool isVisible() const override;
  void update() override;

private:
  float _position;
  float _size;
  short _turtleNumber;
  Fl_PNG_Image *_img;
  bool _visible;
  unsigned int _invisibleTimer;
};

#endif // FROGGER_TURTLE_H
