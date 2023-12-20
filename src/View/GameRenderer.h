#ifndef _GAME_RENDERER_H
#define _GAME_RENDERER_H

#include "../Model/Game.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/fl_draw.H"
#include "View.h"
#include <memory>

class GameRenderer : public View {
public:
  GameRenderer(std::shared_ptr<Game> game, int h, int w)
      : _game{std::move(game)}, WINDOW_HEIGHT{h}, WINDOW_WIDTH{w} {}

  virtual Position getWindowPosition(Position gamePosition);
  virtual void drawVictory();
  virtual void drawGameOver();
  virtual void drawPlayer(std::shared_ptr<Player> player);
  virtual void drawMap();
  virtual void drawHUD();
  virtual void drawLives();
  virtual void drawTime();
  virtual void drawScore();
  virtual void drawMenu();
  void draw() override;

private:
  std::shared_ptr<Game> _game;
  const int WINDOW_HEIGHT;
  const int WINDOW_WIDTH;
};

#endif