#include "GameController.h"
#include <FL/Enumerations.H>
#include <FL/Fl.H>

void GameController::keyPressed(int keycode) {
  if (!game->isOnPause()) {
    switch (keycode) {
    case 'd':
    case FL_Right:
      rightPressed = true;
      game->getPlayer()->move_right();
      break;
    case 'a':
    case 'q':
    case FL_Left:
      leftPressed = true;
      game->getPlayer()->move_left();
      break;
    case 'w':
    case 'z':
    case FL_Up:
      game->getPlayer()->move_up();
      game->handleScore();
      break;
    case 's':
    case FL_Down:
      game->getPlayer()->move_down();
      break;
    }
  }
  if (keycode == FL_Escape) {
    game->triggerMenu();
  }
}

void GameController::keyReleased(int keycode) {
  switch (keycode) {
  case 'd':
  case FL_Right:
    rightPressed = false;
    break;
  case 'a':
  case 'q':
  case FL_Left:
    leftPressed = false;
    break;
  }
}

void GameController::mouseClick(short loc_x, short loc_y) {
  if (game->isOnPause()) {
    for (auto &button : game->getMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
      }
    }
  }
  if (game->isLosing()) {
    for (auto &button : game->getGameOverMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        break;
      }
    }
  }
  if (game->isWinning()) {
    for (auto &button : game->getWinningMenu()->getButtons()) {
      if (button->contains(loc_x, loc_y)) {
        button->onClick();
        break;
      }
    }
  }
}

void GameController::updateMovement() {
  if (rightPressed) {
    game->getPlayer()->move_right();
  }
  if (leftPressed) {
    game->getPlayer()->move_left();
  }
}