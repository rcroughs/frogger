#include "GameEditor.h"
#include "EditorMenu.h"
#include "Environments/Road.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"
#include "Map.h"
#include <memory>

GameEditor::GameEditor(Driver *driver, int width, int height)
    : _driver{driver}, WINDOW_HEIGHT{height}, WINDOW_WIDTH{width} {
  _game = std::make_shared<Game>(_driver);
  _menu = std::make_shared<EditorMenu>(_driver);
  for (int i = 0; i < 13; i++) {
    colors.push_back(new Fl_Color(FL_WHITE));
  }
}

Driver* GameEditor::getDriver() const { return _driver; }

std::shared_ptr<EditorMenu> GameEditor::getMenu() const { return _menu; }

std::shared_ptr<Game> GameEditor::getGame() const { return _game; }

Fl_Color *GameEditor::getColor(short index) const { return colors.at(index); }

std::vector<Fl_Color *> GameEditor::getColors() const { return colors; }

void GameEditor::setColor(Fl_Color *color) {
  colors.at(getCurrentRow()) = color;
}

void GameEditor::addEnvironment(int index, short id) {
  if (_game->getMap()->getEnvironment(index) != nullptr) {
    _game->getMap()->deleteEnvironment(index);
    decreaseEnviNumber();
  }
  // std::cout << "Envi number : " << getEnviNumber() << std::endl;  // --> Pour
  // débug
  if (id == 0) { // SIDEWALK
    addSideWalk(index);
  } else if (id == 1) { // ROAD
    addRoad(index);
  } else if (id == 2) { // WATER
    addWater(index);
  }
}

void GameEditor::deleteEnvironment(int index) {
  _game->getMap()->setEnvironment(index, nullptr);
  decreaseEnviNumber();
}

std::shared_ptr<Environment> GameEditor::getEnvironment(int index) const {
  return getGame()->getMap()->getEnvironment(index);
}

void GameEditor::addSideWalk(int index) {
  getGame()->getMap()->setEnvironment(index, std::make_shared<SideWalk>());
  increaseEnviNumber();
}

void GameEditor::addRoad(int index) {
  if (getRoadCirculation() != '\0' && getRoadSpeedLimit() != 0) {
    _game->getMap()->setEnvironment(
        index, std::make_shared<Road>(getRoadCirculation(), getRoadSpeedLimit()));
    increaseEnviNumber();
    modifyRoadCirculation('\0');
    modifyRoadSpeedLimit(0);
  }
}

void GameEditor::addWater(int index) {
  if (getWaterFlow() != 0) {
    _game->getMap()->setEnvironment(index, std::make_shared<Water>(getWaterFlow()));
    increaseEnviNumber();
    modifyWaterFlow(0);
  }
}

void GameEditor::modifyRoadCirculation(char new_circulation) {
  RoadCirculation = new_circulation;
}

void GameEditor::modifyRoadSpeedLimit(float new_speedLimit) {
  RoadSpeedLimit = new_speedLimit;
}

void GameEditor::modifyWaterFlow(float new_flow) { WaterFlow = new_flow; }

void GameEditor::modifyWaterPropId(short new_prop_id) {
  WaterPropId = new_prop_id;
}

char GameEditor::getRoadCirculation() const { return RoadCirculation; }

float GameEditor::getRoadSpeedLimit() const { return RoadSpeedLimit; }

float GameEditor::getWaterFlow() const { return WaterFlow; }

short GameEditor::getWaterPropId() const { return WaterPropId; }

int GameEditor::getEnviNumber() const { return enviNumber; }

void GameEditor::setEnviNumber(int new_number) { enviNumber = new_number; }

void GameEditor::increaseEnviNumber() { enviNumber++; }

void GameEditor::decreaseEnviNumber() { enviNumber--; }

void GameEditor::changeCurrentRow(int new_row) { currentRow = new_row; }

int GameEditor::getCurrentRow() const { return currentRow; }

void GameEditor::triggerEnvironmentButton() {
  std::vector<std::shared_ptr<Button>> buttons = getMenu()->getButtons();
  for (int i = 0; i < 3; i++) {
    // On cache les boutons d'environnement
    buttons.at(i)->changeState();
  }
}

int GameEditor::getWindowWidth() const { return WINDOW_WIDTH; }

int GameEditor::getWindowHeight() const { return WINDOW_HEIGHT; }