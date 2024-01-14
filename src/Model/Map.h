////////// Map Header File - src/Model/Map.h //////////
// Description: This class represents the map.
// Constructor takes: A mapId: str.
////////// FROGGER ////////////////////////////////////////

#ifndef FROGGER_MAP_H
#define FROGGER_MAP_H

#include "array"
#include <memory>
#include <string>

// Forward declaration
class Environment;
class Game;

// Enumerations for the mapId
enum EnvironmentType { LOG = '1', TURTLE = '2', ROAD = '3', SIDEWALK = '4' };
enum Directions { LEFT = '0', RIGHT = '1' };
enum Speed { SLOW = 1, MEDIUM = 2, FAST = 3 };

class Map {
public:
  // Constructor without any arguments (deprecated)
  Map();
  // Creates a map with the given mapId.
  Map(std::string mapId);

  // Getters and setters for the environments array.
  // Does not take any arguments.
  [[nodiscard]] virtual std::shared_ptr<Environment> getEnvironment(int index) const;
  virtual void deleteEnvironment(int index);
  virtual void setEnvironment(int index,
                              std::shared_ptr<Environment> new_environment);
  virtual void resetEnvironments();

  // Updates the props of all environments.
  // Does not take any arguments and returns void
  virtual void updateProps() const;

  // Handles the game
  // Takes the game running
  virtual void handleGame(Game *currentGame) const;

  // Creates all the environments with the given mapId.
  // Takes the mapId as a string and returns a boolean.
  virtual bool createMap(std::string mapId);

  //Returns the mapId of the map.
  //Does not take any arguments and returns a string.
  virtual std::string getMapId() const;

protected:

  // Subfunctions for createMap.
  virtual bool createLogEnvironment(std::string mapId, int &stringCount, int environmentCount);
  virtual bool createTurtleEnvironment(std::string mapId, int &stringCount, int environmentCount);
  virtual bool createRoadEnvironment(std::string mapId, int &stringCount, int environmentCount);

private:
  std::array<std::shared_ptr<Environment>, 13> environments{nullptr};
};

#endif // FROGGER_MAP_H