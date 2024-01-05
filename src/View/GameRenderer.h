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
  GameRenderer(std::shared_ptr<Game> game, int h, int w);

  virtual Position getWindowPosition(Position gamePosition) const;
  virtual void drawVictory() const;
  virtual void drawGameOver() const;
  virtual void drawPlayer(std::shared_ptr<Player> player) const;
  virtual void drawMap() const;
  virtual void drawHUD() const;
  virtual void drawLives() const;
  virtual void drawTime() const;
  virtual void drawScore() const;
  virtual void drawMenu() const;
  void draw() const override;

private:
  std::shared_ptr<Game> _game;
  const int WINDOW_HEIGHT;
  const int WINDOW_WIDTH;
};

#endif