#include "GameRenderer.h"
#include <iostream>

void GameRenderer::draw() {
    Position player_position = game->getPlayer().getPosition();
    fl_draw_box(FL_FLAT_BOX, player_position.x, player_position.y, 50, 50, FL_GREEN);
}