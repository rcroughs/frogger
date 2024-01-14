#include "GameController.h"
#include <FL/Enumerations.H>
#include <FL/Fl.H>

GameController::GameController(std::shared_ptr<Game> game)
    : _game{std::move(game)}, _leftPressed{false}, _rightPressed{false} {}

void GameController::mouseMove(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}

void GameController::mouseClick(short loc_x, short loc_y) {
  if (_game->isOnPause()) {
    for (auto &button : _game->getMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
      }
    }
  }
  else if (_game->isLosing()) {
    for (auto &button : _game->getGameOverMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        break;
      }
    }
  }
  else if (_game->isWinning()) {
    for (auto &button : _game->getWinningMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        break;
      }
    }
  }
}

void GameController::mouseRelease(short loc_x, short loc_y) {
  static_cast<void>(loc_x);
  static_cast<void>(loc_y);
}

void GameController::keyPressed(int keycode) {
  if (!_game->isOnPause()) {
    switch (keycode) {
    case 'd':
    case FL_Right:
      _rightPressed = true;
      _game->movePlayerRight();
      break;
    case 'a':
    case 'q':
    case FL_Left:
      _leftPressed = true;
      _game->movePlayerLeft();
      break;
    case 'w':
    case 'z':
    case FL_Up:
      _game->movePlayerUp();
      _game->handleScore();
      break;
    case 's':
    case FL_Down:
      _game->movePlayerDown();
      break;
    }
  }
  if (keycode == FL_Escape) {
    _game->triggerMenu();
  }
}

void GameController::keyReleased(int keycode) {
  switch (keycode) {
  case 'd':
  case FL_Right:
    _rightPressed = false;
    break;
  case 'a':
  case 'q':
  case FL_Left:
    _leftPressed = false;
    break;
  }
}

void GameController::updateMovement() {
  if (_rightPressed) {
    _game->movePlayerRight();
  }
  if (_leftPressed) {
    _game->movePlayerLeft();
  }
}