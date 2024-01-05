#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"
#include <memory>

class Game;

class SideWalk : virtual public Environment {
public:
  SideWalk();
  ~SideWalk() = default;

  [[nodiscard]]virtual Fl_Color getColor() const override;
  virtual void setColor(Fl_Color new_color);

  [[nodiscard]]virtual std::vector<std::shared_ptr<Prop>> getProps() const override;
  virtual void handleGame(Game *currentGame) override;
  virtual void updateProps() override;
  virtual void generateProps(short id) override;
  [[nodiscard]] virtual std::string getId() const override;

private:
  Fl_Color _color;
  std::vector<std::shared_ptr<Prop>> _props;
  std::string _id;
};

#endif