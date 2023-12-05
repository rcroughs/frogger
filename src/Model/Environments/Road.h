#ifndef SRC_ROAD_H
#define SRC_ROAD_H

#include "FL/Fl.H"
#include "../Environment.h"
#include "Props/Prop.h"
#include "vector"

class Road : virtual public Environment {
private:
    Fl_Color color;
    std::vector<Prop*> props;
    char circulation;
    float speedLimit;
public:
    Road(char circulation, float speedLimit) : color{FL_GRAY}, props{}, circulation{circulation}, speedLimit{speedLimit} {}
    ~Road() {
        for (int i = 0; i < props.size(); i++) {
            delete props.at(i);
        }
    }

    virtual Fl_Color getColor() {return color;}
    char getCirculation () {return circulation;}

    virtual void generateProps(short id) override;
    void generateCars();

    virtual std::vector<Prop*>& getProps() override;
    virtual void handleGame(Game* currentGame) override;
    virtual void updateProps() override;
};

#endif //SRC_ROAD_H
