#include "GameRenderer.h"

Position GameRenderer::getWindowPosition(Position gamePosition) {
    Position res = {int(WINDOW_WIDTH * (float(gamePosition.x) / (WINDOW_WIDTH/10.0))) ,int(((float(gamePosition.y) / 13.0) * WINDOW_HEIGHT)) };
    return res;
}

void GameRenderer::draw() {
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