#ifndef SRC_GAMECONTROLLER_H
#define SRC_GAMECONTROLLER_H

#include "../Model/Game.h"
#include "Controller.h"
#include "array"
#include "vector"
#include <memory>

class GameController : public Controller {
public:
  GameController(std::shared_ptr<Game> game)
      : game{std::move(game)}, leftPressed{false}, rightPressed{false} {}

  virtual void mouseMove(short loc_x, short loc_y) override{};
  virtual void mouseClick(short loc_x, short loc_y) override;
  virtual void mouseRelease(short loc_x, short loc_y) override{};
  virtual void keyPressed(int keycode) override;
  virtual void keyReleased(int keycode) override;
  virtual void updateMovement() override;

private:
  std::shared_ptr<Game> game;
  bool leftPressed;
  bool rightPressed;

};

#endif // SRC_GAMECONTROLLER_H
