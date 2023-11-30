#include "GameRenderer.h"
#include "../Model/Environment.h"
#include <array>

Position GameRenderer::getWindowPosition(Position gamePosition) {
    Position res = {float(WINDOW_WIDTH * (gamePosition.x/100.0f)) ,int((float(WINDOW_HEIGHT) - float(WINDOW_HEIGHT) / 13.0f) - ((float(gamePosition.y) / 13.0f) * WINDOW_HEIGHT)) };
    return res;
}

void GameRenderer::drawVictory() {
    fl_draw_box(FL_FLAT_BOX, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, FL_GREEN);
    fl_color(FL_BLACK);
    fl_draw("Victoire !", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, FL_ALIGN_CENTER);
}

void GameRenderer::drawGameOver() {
    fl_draw_box(FL_FLAT_BOX, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, FL_RED);
    fl_color(FL_BLACK);
    fl_draw("Game Over !", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, FL_ALIGN_CENTER);
}

void GameRenderer::drawPlayer() {
    Position player_position = game->getPlayer()->getPosition();
    Position windowPosition = getWindowPosition(player_position);
    Direction current_direction = game->getPlayer()->getDirection();

    int x1, x2, x3;
    int y1, y2, y3;

    // On vérifie la direction de la grenouille
    if (current_direction == right) {
        x1 = windowPosition.x; y1 = windowPosition.y;
        x2 = windowPosition.x+50; y2 = windowPosition.y+25;
        x3 = windowPosition.x; y3 = windowPosition.y+50;
    }
    else if (current_direction == left) {
        x1 = windowPosition.x + 50; y1 = windowPosition.y;
        x2 = windowPosition.x; y2 = windowPosition.y+25;
        x3 = windowPosition.x+50; y3 = windowPosition.y+50;
    }
    else if (current_direction == up) {
        x1 = windowPosition.x + 25; y1 = windowPosition.y;
        x2 = windowPosition.x; y2 = windowPosition.y+50;
        x3 = windowPosition.x+50; y3 = windowPosition.y+50;
    }
    else {
        x1 = windowPosition.x; y1 = windowPosition.y;
        x2 = windowPosition.x+50; y2 = windowPosition.y;
        x3 = windowPosition.x+25; y3 = windowPosition.y+50;
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
        Environment* currentEnvironment = game->getMap()->getEnvironment(i);
        fl_draw_box(FL_FLAT_BOX, 0, (WINDOW_HEIGHT - (WINDOW_HEIGHT / 13.0f)) - (i * (WINDOW_HEIGHT / 13.0)), WINDOW_WIDTH, int(float(WINDOW_HEIGHT) / 13.0f), currentEnvironment->getColor());
        std::vector<Prop*> props = currentEnvironment->getProps();
        if (!props.empty()) {
            for (int j = 0; j < props.size(); j++) {
                float propPosition = props[j]->getPosition();
                Position windowPosition = getWindowPosition(Position{propPosition, i});
                fl_draw_box(FL_FLAT_BOX, windowPosition.x, windowPosition.y + 10, (props.at(j)->getSize() / 100.0f) * WINDOW_WIDTH, 35, props[j]->getColor());
            }
        }
    }
}

void GameRenderer::draw() {
    if (game->isLosing()) {
        drawGameOver();
    }
    else if (game->isWinning()) {
        drawVictory();
    } else {
        drawMap();
        drawPlayer();
    }
}