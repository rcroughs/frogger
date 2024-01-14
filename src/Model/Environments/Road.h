////////// Road Header File - src/Model/Environments/Road.h //////////
// Description: This class represents the road environment.
// Inherited from Environment.
// Constructor takes: a circulation direction , a speed limit and a propsId.
// Constructor takes: a circulation direction and a speed limit and does not create props.
////////// FROGGER ////////////////////////////////////////

#ifndef _FROGGER_ROAD_H
#define _FROGGER_ROAD_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"
#include <memory>
#include <string>

class Road : virtual public Environment {
public:
  Road(char circulation, float speedLimit, short propsId);
  Road(char circulation, float speedLimit);
  ~Road() = default;

  // Getters
  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual char getCirculation() const;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Prop>> getProps() const override;
  [[nodiscard]] virtual std::string getId() const override;

  // Generate props
  virtual void generateProps(short id) override;

  // Game handler
  virtual void handleGame(Game *currentGame) override;
  // Update props on the environment
  virtual void updateProps() override;

private:
  virtual void generateCars();

  Fl_Color _color;
  std::vector<std::shared_ptr<Prop>> _props;
  char _circulation;
  float _speedLimit;
  std::string _id;
};

#endif // _FROGGER_ROAD_H
