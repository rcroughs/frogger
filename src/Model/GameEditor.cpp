#include "GameEditor.h"
#include "EditorMenu.h"
#include "Environments/Road.h"
#include "Environments/SideWalk.h"
#include "Environments/Water.h"
#include <memory>

GameEditor::GameEditor(Driver* driver, int width, int height)
    : _driver{driver}, WINDOW_WIDTH{width}, WINDOW_HEIGHT{height} {
  _game = std::make_shared<Game>(_driver);
  _menu = std::make_shared<EditorMenu>(_driver);
  for (int i = 0; i < 13; i++) {
    colors.push_back(new Fl_Color(FL_WHITE));
  }
}

Environment *GameEditor::getEnvironment(int index) {
  return getGame()->getMap()->getEnvironment(index);
}

void GameEditor::addSideWalk(int index) {
  getGame()->getMap()->setEnvironment(index, new SideWalk());
  increaseEnviNumber();
}

void GameEditor::addRoad(int index) {
  if (getRoadCirculation() != '\0' && getRoadSpeedLimit() != 0) {
    _game->getMap()->setEnvironment(
        index, new Road(getRoadCirculation(), getRoadSpeedLimit()));
    increaseEnviNumber();
    modifyRoadCirculation('\0');
    modifyRoadSpeedLimit(0);
  }
}

void GameEditor::addWater(int index) {
  if (getWaterFlow() != 0) {
    _game->getMap()->setEnvironment(index, new Water(getWaterFlow()));
    increaseEnviNumber();
    modifyWaterFlow(0);
  }
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

void GameEditor::triggerEnvironmentButton() {
  std::vector<Button *> buttons = getMenu()->getButtons();
  for (int i = 0; i < 3; i++) {
    // On cache les boutons d'environnement
    buttons.at(i)->changeState();
  }
}
