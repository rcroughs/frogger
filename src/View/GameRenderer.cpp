#include "GameRenderer.h"

Position GameRenderer::getWindowPosition(Position gamePosition) {
    Position res = {int(WINDOW_WIDTH * (float(gamePosition.x) / (WINDOW_WIDTH/10.0))) ,int(((float(gamePosition.y) / 13.0) * WINDOW_HEIGHT)) };
    return res;
}

void GameRenderer::draw() {
    Position player_position = game->getPlayer()->getPosition();
    Position windowPosition = getWindowPosition(player_position);
    fl_draw_box(FL_FLAT_BOX, windowPosition.x, windowPosition.y, 50, 50, FL_GREEN);
}