////////// Environment Header File - src/Model/Environment.h //////////
// Description: Interface for the environments.
////////// FROGGER ////////////////////////////////////////

#ifndef _FROGGER_ENVIRONMENT_H
#define _FROGGER_ENVIRONMENT_H

#include "FL/Fl.H"
#include <memory>
#include <vector>

// Forward declarations
class Game;
class Prop;

// interface
class Environment {
public:
  // Getters
  [[nodiscard]] virtual Fl_Color getColor() const = 0;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Prop>> getProps() const = 0;
  [[nodiscard]] virtual std::string getId() const = 0;

  // Game handler
  // Takes the game running
  virtual void handleGame(Game *currentGame) = 0;

  // Update props on the environment
  virtual void updateProps() = 0;

  // Generate props on the environment
  virtual void generateProps(short id) = 0;
};

#endif // _FROGGER_ENVIRONMENT_H