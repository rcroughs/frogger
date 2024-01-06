#ifndef SRC_ROAD_H
#define SRC_ROAD_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"
#include <memory>

class Road : virtual public Environment {
public:
  Road(char circulation, float speedLimit, short propsId);
  Road(char circulation, float speedLimit);
  ~Road() = default;

  [[nodiscard]] virtual Fl_Color getColor() const override;
  [[nodiscard]] virtual char getCirculation() const;

  virtual void generateProps(short id) override;

  [[nodiscard]] virtual std::vector<std::shared_ptr<Prop>> getProps() const override;
  virtual void handleGame(Game *currentGame) override;
  virtual void updateProps() override;
  [[nodiscard]] virtual std::string getId() const override;

private:
  virtual void generateCars();

  Fl_Color _color;
  std::vector<std::shared_ptr<Prop>> _props;
  char _circulation;
  float _speedLimit;
  std::string _id;
};

#endif // SRC_ROAD_H
