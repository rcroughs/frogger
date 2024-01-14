#ifndef FROGGER_LILYPAD_H
#define FROGGER_LILYPAD_H

#include "../../Game.h"
#include "FL/Fl.H"
#include "Prop.h"
#include <FL/Fl_PNG_Image.H>

class LilyPad : public Prop {
public:
  LilyPad(float leftCornerPos);
  ~LilyPad();

  // Getters
  [[nodiscard]] virtual float getPosition() const override;
  [[nodiscard]] virtual float getRightCorner() const override;
  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual float getSize() const override;
  [[nodiscard]] virtual bool contains(float playerPosition) const override;
  [[nodiscard]] virtual bool hasImage() const override;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const override;
  [[nodiscard]] virtual bool isVisible() const override;
  
  // Move a prop
  virtual void move() override;
  // Handle game
  virtual void handleGame(Game *currentGame) override;
  // Update prop position
  virtual void update() override;

private:
  Fl_PNG_Image *_image;
  float _leftCorner;
  float _size{5};
  bool _hasTurtle;

};

#endif // FROGGER_LILYPAD_H
