#ifndef FROGGER_CAR_H
#define FROGGER_CAR_H

#include "../../Game.h"
#include "../../Position.h"
#include "FL/Fl.H"
#include "Prop.h"
#include "iostream"

class Car : public Prop {
public:
  Car(float initPosition, short colorId, char direction, float speed);
  ~Car();

  [[nodiscard]] virtual float getPosition() const override;
  [[nodiscard]] virtual float getRightCorner() const override;
  [[nodiscard]] virtual float getSize() const override;
  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual bool contains(float playerPosition) const override;
  virtual void move() override;
  virtual void handleGame(Game *currentGame) override;
  [[nodiscard]] virtual bool hasImage() const override;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual bool isVisible() const override;
  virtual void update() override;

private:
  float _size;
  float _leftCorner;
  Fl_Color _color;
  Fl_PNG_Image *_img;
  char _direction;
  float _speed;
};

#endif // FROGGER_CAR_H
