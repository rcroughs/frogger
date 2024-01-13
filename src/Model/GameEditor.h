#ifndef SRC_GAMEEDITOR_H
#define SRC_GAMEEDITOR_H

#include "../Driver.h"
#include "../Model/Environment.h"
#include "PauseMenu.h"
#include "EditorMenu.h"
#include "Game.h"
#include <memory>

class Driver;
class Environment;
class EditorMenu;
class Game;

class GameEditor {
public:
  GameEditor(Driver* driver, int width, int height);

  // IMPORTANT GETTERS
  [[nodiscard]] virtual Driver* getDriver() const;
  [[nodiscard]] virtual std::shared_ptr<EditorMenu> getMenu() const;
  [[nodiscard]] virtual std::shared_ptr<Game> getGame() const;

  // Information about the environment's colors (even when not already
  // configured)
  [[nodiscard]] virtual Fl_Color *getColor(short index) const;
  [[nodiscard]] virtual std::vector<Fl_Color *> getColors() const;
  virtual void setColor(Fl_Color *color);

  // Add & Delete & Get an environment
  virtual void addEnvironment(int index, short id);
  virtual void deleteEnvironment(int index);
  virtual void checkEnvironment(int index);
  std::shared_ptr<Environment> getEnvironment(int index) const;

  // Add a specific environment, used by addEnvironment()
  virtual void addRoad(int index);
  virtual void addSideWalk(int index);
  virtual void addWater(int index);

  // Parameters --> Setters and Getters
  virtual void modifyRoadCirculation(char new_circulation);
  virtual void modifyRoadSpeedLimit(float new_speedLimit);
  virtual void modifyWaterFlow(float new_flow);
  virtual void modifyWaterPropId(short new_prop_id);
  [[nodiscard]] virtual char getRoadCirculation() const;
  [[nodiscard]] virtual float getRoadSpeedLimit() const;
  [[nodiscard]] virtual float getWaterFlow() const;
  [[nodiscard]] virtual short getWaterPropId() const;

  // Information about the already existing environments
  [[nodiscard]] virtual int getEnviNumber() const;
  virtual void setEnviNumber(int new_number);
  virtual void increaseEnviNumber();
  virtual void decreaseEnviNumber();

  // Information about the mouse's position --> selection
  virtual void changeCurrentRow(int new_row);
  [[nodiscard]] virtual int getCurrentRow() const;

  // Shows/Hides specific buttons
  virtual void triggerEnvironmentButton();
  virtual void triggerSpeedButtons();
  virtual void triggerPropsButtons();
  virtual void triggerDirectionButtons();
  virtual void triggerPauseMenu();

  // Getters for the windows's dimensions
  [[nodiscard]] virtual int getWindowWidth() const;
  [[nodiscard]] virtual int getWindowHeight() const;

  // Pause menu
  [[nodiscard]] virtual std::shared_ptr<PauseMenu> getPauseMenu() const;
  [[nodiscard]] virtual bool isPaused() const;
  
private:
  std::shared_ptr<Game> _game;
  Driver* _driver;
  std::shared_ptr<EditorMenu> _menu;
  std::shared_ptr<PauseMenu> _pauseMenu;

  int enviNumber{1}; // Must be 12 to start a game, counting from 0

  enum ENVIRONMENT { ROAD, SIDEWALK, WATER };

  std::vector<Fl_Color *> colors;
  const int WINDOW_HEIGHT;
  const int WINDOW_WIDTH;

  // Road Parameters
  char RoadCirculation{'\0'};
  float RoadSpeedLimit{-1};

  // Water Parameters --> PropId does not have to be modified, it will be used
  // for generateProps(id) and CAN be modified
  float WaterFlow{-1};
  short WaterPropId{-1};

  // Mouse on row
  int currentRow;

};

#endif // SRC_GAMEEDITOR_H
