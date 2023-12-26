#ifndef SRC_ROAD_H
#define SRC_ROAD_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"

class Road : virtual public Environment {
public:
  Road(char circulation, float speedLimit)
      : color{FL_GRAY}, props{}, circulation{circulation},
        speedLimit{speedLimit} {
          id += "3"; 
          id += circulation == 'l' ? "0" : "1";
          std::string speedLimitId;
          if (speedLimit == 1.0f) {
            speedLimitId = "1";
          } else if (speedLimit == 1.5f) {
            speedLimitId = "2";
          } else if (speedLimit == 2.0f) {
            speedLimitId = "3";
          }
          id += speedLimitId;
        }
  ~Road() {
    for (int i = 0; i < props.size(); i++) {
      delete props.at(i);
    }
  }

  virtual Fl_Color getColor() { return color; }
  char getCirculation() { return circulation; }

  virtual void generateProps(short id) override;
  void generateCars();

  virtual std::vector<Prop *> &getProps() override;
  virtual void handleGame(Game *currentGame) override;
  virtual void updateProps() override;
  std::string getId() override { return id; }

private:
  Fl_Color color;
  std::vector<Prop *> props;
  char circulation;
  float speedLimit;
  std::string id;

};

#endif // SRC_ROAD_H
