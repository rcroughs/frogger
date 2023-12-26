#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"

class Game;

class SideWalk : virtual public Environment {
private:
  Fl_Color color;
  std::vector<Prop *> props;
  std::string id;

public:
  SideWalk() : color{FL_BLACK}, props{}, id{"4"} {}
  ~SideWalk() = default;

  virtual Fl_Color getColor() { return color; }
  virtual void setColor(Fl_Color new_color) { color = new_color; }

  virtual std::vector<Prop *> &getProps() override;
  virtual void handleGame(Game *currentGame) override;
  virtual void updateProps() override;
  virtual void generateProps(short id) override {}
  std::string getId() override { return id; }
};

#endif