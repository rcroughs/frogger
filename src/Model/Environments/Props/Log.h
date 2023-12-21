#include "../../Game.h"
#include "../../Position.h"
#include "FL/Fl.H"
#include "Prop.h"

class Log : public Prop {
public:
  Log(float size, float initPosition, float speed)
      : size{size}, leftCorner{initPosition}, speed{speed},
        color{fl_rgb_color(150, 75, 0)} {};

  virtual float getPosition() override { return leftCorner; }
  virtual float getRightCorner() override { return leftCorner + size; }
  virtual Fl_Color getColor() override { return color; }
  virtual float getSize() override { return size; }
  virtual bool contains(float playerPosition) override;
  virtual void move() override;
  virtual void handleGame(Game *currentGame);
  virtual bool hasImage() override { return false; }
  virtual Fl_PNG_Image *getImage() { return nullptr; };
  bool isVisible() override { return true; }
  void update() override {};

private:
  float size;
  float leftCorner;
  float speed;
  Fl_Color color;
};
