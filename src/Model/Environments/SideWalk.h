////////// SideWalk Header File - src/Model/Environments/SideWalk.h //////////
// Description: This class represents the sidewalk environment.
// Inherited from Environment.
// Constructor takes: void
////////// FROGGER ////////////////////////////////////////

#ifndef SIDEWALK_H
#define SIDEWALK_H

#include "../Environment.h"
#include "FL/Fl.H"
#include "Props/Prop.h"
#include "vector"
#include <memory>
#include <string>

// Forward declaration
class Game;

class SideWalk : virtual public Environment {
public:
  SideWalk();
  ~SideWalk() = default;

  // Getters & Setters
  [[nodiscard]]virtual Fl_Color getColor() const override;
  [[nodiscard]]virtual std::vector<std::shared_ptr<Prop>> getProps() const override;
  [[nodiscard]] virtual std::string getId() const override;
  virtual void setColor(Fl_Color new_color);

  // Generate props
  virtual void generateProps(short id) override;

  // Game handler
  virtual void handleGame(Game *currentGame) override;

  // Update props on the environment
  virtual void updateProps() override;

private:
  Fl_Color _color;
  std::vector<std::shared_ptr<Prop>> _props;
  std::string _id;
};

#endif