#ifndef FROGGER_WATER_H
#define FROGGER_WATER_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"
#include <memory>
#include <string>

class Water : virtual public Environment {
public:
  Water(float speed);
  Water();
  [[nodiscard]] virtual Fl_Color getColor() const override;
  virtual void setColor(Fl_Color new_color);
  virtual void setFlow(float new_flow);

  virtual void generateLogs();
  virtual void generateLilyPads();
  virtual void generateTurtles(short id);

  virtual void generateProps(short id) override;

  virtual void handleGame(Game *currentGame) override;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Prop>> getProps() const override;
  virtual void updateProps() override;
  [[nodiscard]] virtual std::string getId() const override; 

private:
  Fl_Color _color;
  std::vector<std::shared_ptr<Prop>> _props;
  bool _isMoving;
  float _flow;
  std::string _id;
};

#endif // FROGGER_WATER_H