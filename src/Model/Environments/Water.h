////////// Water Header File - src/Model/Environments/Water.h //////////
// Description: This class represents the water environment.
// Inherited from Environment.
// Constructor takes: A speed, a propsId.
// Constructor takes: A speed and does not create props.
////////// FROGGER ////////////////////////////////////////

#ifndef _FROGGER_WATER_H
#define _FROGGER_WATER_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"
#include <memory>
#include <string>

class Water : virtual public Environment {
public:
  Water(float speed, short propsId);
  Water(float speed);
  Water();

  // Getters
  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Prop>> getProps() const override;
  [[nodiscard]] virtual std::string getId() const override; 
  virtual void setColor(Fl_Color new_color);
  virtual void setFlow(float new_flow);

  // Generate props
  virtual void generateLogs();
  virtual void generateLilyPads();
  virtual void generateTurtles(short id);

  // Generate a props from a given id
  virtual void generateProps(short id) override;

  // Game handler
  virtual void handleGame(Game *currentGame) override;

  // Update props on the environment
  virtual void updateProps() override;

private:
  Fl_Color _color;
  std::vector<std::shared_ptr<Prop>> _props;
  bool _isMoving;
  float _flow;
  std::string _id;
};

#endif // _FROGGER_WATER_H