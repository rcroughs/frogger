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
  _pauseMenu = std::make_shared<PauseMenu>(150, 100, _driver);
  for (int i = 0; i < 13; i++) {
    if (i == 0) {
        colors.push_back(new Fl_Color(FL_BLACK));
    } else if (i == 12) {
        colors.push_back(new Fl_Color(FL_BLUE));
    } else {
        colors.push_back(new Fl_Color(FL_WHITE));
    }
  }
  // Default environment configuration
  _game->getMap()->setEnvironment(0, std::make_shared<SideWalk>(SideWalk()));
  _game->getMap()->setEnvironment(12, std::make_shared<Water>(Water(0, 1)));
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
  if (id == 0) { // SIDEWALK
    addSideWalk(index);
  } else if (id == 1) { // ROAD
    addRoad(index);
  } else if (id == 2) { // WATER
    addWater(index);
  }
}

void GameEditor::checkEnvironment(int index) {
    if (_game->getMap()->getEnvironment(index) != nullptr) {
        _game->getMap()->deleteEnvironment(index);
        decreaseEnviNumber();
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
    checkEnvironment(index);
  getGame()->getMap()->setEnvironment(index, std::make_shared<SideWalk>());
  increaseEnviNumber();
}

void GameEditor::addRoad(int index) {
    checkEnvironment(index);
  if (getRoadCirculation() != '\0' && getRoadSpeedLimit() != -1) {
    _game->getMap()->setEnvironment(
            index, std::make_shared<Road>(getRoadCirculation(), getRoadSpeedLimit(), 0));
    increaseEnviNumber();
    modifyRoadSpeedLimit(-1);
    modifyWaterFlow(-1);
    modifyRoadCirculation('\0');
    triggerEnvironmentButton();
  }
}

void GameEditor::addWater(int index) {
    checkEnvironment(index);
  if (getWaterFlow() != -1 && getWaterPropId() != -1) {
    _game->getMap()->setEnvironment(index, std::make_shared<Water>(getWaterFlow(), getWaterPropId()));
    increaseEnviNumber();
    modifyWaterFlow(-1);
    modifyRoadSpeedLimit(-1);
    modifyWaterPropId(-1);
    triggerEnvironmentButton();
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
    // On cache/montre les boutons d'environnement
    buttons.at(i)->changeState();
  }
}

void GameEditor::triggerSpeedButtons() {
    std::vector<std::shared_ptr<Button>> buttons = getMenu()->getButtons();
    for (int i = 3; i < 6; i++) {
        // On cache/montre les boutons de vitesse
        buttons.at(i)->changeState();
    }
}

void GameEditor::triggerPropsButtons() {
    std::vector<std::shared_ptr<Button>> buttons = getMenu()->getButtons();
    for (int i = 6; i < 8; i++) {
        // On cache/montre les boutons de props
        buttons.at(i)->changeState();
    }
}

void GameEditor::triggerDirectionButtons() {
    std::vector<std::shared_ptr<Button>> buttons = getMenu()->getButtons();
    for (int i = 8; i < 10; i++) {
        // On cache/montre les boutons de direction
        buttons.at(i)->changeState();
    }
}

void GameEditor::triggerPauseMenu() {
    _pauseMenu->triggerMenu();
}

int GameEditor::getWindowWidth() const { return WINDOW_WIDTH; }

int GameEditor::getWindowHeight() const { return WINDOW_HEIGHT; }

std::shared_ptr<PauseMenu> GameEditor::getPauseMenu() const { return _pauseMenu; }

bool GameEditor::isPaused() const { return _pauseMenu->isOpen(); }