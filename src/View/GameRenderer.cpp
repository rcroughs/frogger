#include "GameRenderer.h"
#include "../Model/Environment.h"
#include "../Model/GameMenu.h"
#include "../Model/Player.h"
#include "FL/Fl_Image.H"
#include "FL/Fl_PNG_Image.H"
#include "vector"
#include <memory>
#include <string>

Position GameRenderer::getWindowPosition(Position gamePosition) {
  Position res = {float(WINDOW_WIDTH * (gamePosition.x / 100.0f)),
                  int((float(WINDOW_HEIGHT) - float(WINDOW_HEIGHT) / 13.0f) -
                      ((float(gamePosition.y) / 13.0f) * WINDOW_HEIGHT))};
  return res;
}

void GameRenderer::drawVictory() {
  _game->getWinningMenu()->getImage()->draw(0, 0);
  for (auto &button : _game->getWinningMenu()->getButtons()) {
    button->getImage()->draw(button->getX(), button->getY());
  }
}

void GameRenderer::drawGameOver() {
  _game->getGameOverMenu()->getImage()->draw(0, 0);
  for (auto &button : _game->getGameOverMenu()->getButtons()) {
    button->getImage()->draw(button->getX(), button->getY());
  }
}

void GameRenderer::drawPlayer(std::shared_ptr<Player> player) {
  Position player_position = player->getPosition();
  Position windowPosition = getWindowPosition(player_position);
  Direction current_direction = player->getDirection();

  int x1, x2, x3;
  int y1, y2, y3;

  // On vérifie la direction de la grenouille
  if (current_direction == right) {
    x1 = windowPosition.x;
    y1 = windowPosition.y;
    x2 = windowPosition.x + 50;
    y2 = windowPosition.y + 25;
    x3 = windowPosition.x;
    y3 = windowPosition.y + 50;
  } else if (current_direction == left) {
    x1 = windowPosition.x + 50;
    y1 = windowPosition.y;
    x2 = windowPosition.x;
    y2 = windowPosition.y + 25;
    x3 = windowPosition.x + 50;
    y3 = windowPosition.y + 50;
  } else if (current_direction == up) {
    x1 = windowPosition.x + 25;
    y1 = windowPosition.y;
    x2 = windowPosition.x;
    y2 = windowPosition.y + 50;
    x3 = windowPosition.x + 50;
    y3 = windowPosition.y + 50;
  } else {
    x1 = windowPosition.x;
    y1 = windowPosition.y;
    x2 = windowPosition.x + 50;
    y2 = windowPosition.y;
    x3 = windowPosition.x + 25;
    y3 = windowPosition.y + 50;
  }

  fl_color(FL_GREEN);

  // Dessin du triangle --> 3 points qui se rejoignent
  fl_begin_polygon();
  fl_vertex(x1, y1);
  fl_vertex(x2, y2);
  fl_vertex(x3, y3);
  fl_end_polygon();
}

void GameRenderer::drawMap() {
  for (int i = 0; i < 13; i++) {
    Environment *currentEnvironment = _game->getMap()->getEnvironment(i);
    fl_draw_box(FL_FLAT_BOX, 0,
                (WINDOW_HEIGHT - (WINDOW_HEIGHT / 13.0f)) -
                    (i * (WINDOW_HEIGHT / 13.0)),
                WINDOW_WIDTH, int(float(WINDOW_HEIGHT) / 13.0f),
                currentEnvironment->getColor());
    std::vector<Prop *> props = currentEnvironment->getProps();
    if (!props.empty()) {
      for (int j = 0; j < props.size(); j++) {
        float propPosition = props[j]->getPosition();
        Position windowPosition = getWindowPosition(Position{propPosition, i});
        if (props.at(j)->hasImage() && props.at(j)->isVisible()) {
          props.at(j)->getImage()->draw(
              windowPosition.x, windowPosition.y);
        } else if (props.at(j)->isVisible()) {
          fl_draw_box(FL_FLAT_BOX, windowPosition.x, windowPosition.y + 10,
                      (props.at(j)->getSize() / 100.0f) * WINDOW_WIDTH, 35,
                      props[j]->getColor());
        }
      }
    }
  }
}

void GameRenderer::drawLives() {
  short numberLives = _game->getLives();
  if (numberLives == 3) {
    Fl_PNG_Image lives("res/three_hearts.png");
    Fl_Image *smallerImg = lives.copy(100, 30);
    smallerImg->draw(290, 710);
  } else if (numberLives == 2) {
    Fl_PNG_Image lives("res/two_hearts.png");
    Fl_Image *smallerImg = lives.copy(100, 30);
    smallerImg->draw(290, 710);
  } else if (numberLives == 1) {
    Fl_PNG_Image lives("res/one_heart.png");
    Fl_Image *smallerImg = lives.copy(100, 30);
    smallerImg->draw(290, 710);
  } else {
    Fl_PNG_Image lives("res/no_heart.png");
    Fl_Image *smallerImg = lives.copy(100, 30);
    smallerImg->draw(290, 710);
  }
}

void GameRenderer::drawTime() {
  float length = 270 - ((_game->getTime() * 60 - _game->getFrameLeft()) *
                        (270 / (_game->getTime() * 60)));
  fl_draw_box(FL_FLAT_BOX, 410, 710, length, 30, FL_RED);
  fl_draw_box(FL_FLAT_BOX, 410 + length, 710, 270 - length, 30, FL_WHITE);
  fl_frame("AAAA", 410, 710, 270, 30);
}

void GameRenderer::drawScore() {
  Fl_PNG_Image score("res/score.png");
  score.draw(10, 706);
  fl_font(FL_HELVETICA_BOLD, 50);
  fl_draw(std::to_string(_game->getScore()).c_str(), 160, 740);
}

void GameRenderer::drawHUD() {
  // Dessin des vies
  drawLives();
  // Dessin de la barre de temps restant
  drawTime();
  // Affichage du score
  drawScore();
}

void GameRenderer::drawMenu() {
  std::shared_ptr<GameMenu> gameMenu = _game->getMenu();
  gameMenu->getImage()->draw(gameMenu->getX(), gameMenu->getY());
  for (auto &button : gameMenu->getButtons()) {
    button->getImage()->draw(button->getX(), button->getY());
  }
}

void GameRenderer::draw() {
  if (_game->isLosing()) {
    drawGameOver();
  } else if (_game->isWinning()) {
    drawVictory();
  } else {
    drawMap();
    drawPlayer(_game->getPlayer());
    std::vector<std::shared_ptr<Player>> winnerPlayer = _game->getWinnerPlayer();
    for (int i = 0; i < winnerPlayer.size(); i++) {
      drawPlayer(winnerPlayer.at(i));
    }
    drawHUD();
    if (_game->isOnPause()) {
      drawMenu();
    }
  }
}