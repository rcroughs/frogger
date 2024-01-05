#include "Log.h"
#include "../../Game.h"
#include "../../Player.h"
#include <memory>

Log::Log(float size, float initPosition, float speed)
    : _size{size}, _leftCorner{initPosition}, _speed{speed},
      _color{fl_rgb_color(150, 75, 0)} {};

float Log::getPosition() const { return _leftCorner; }

float Log::getRightCorner() const { return _leftCorner + _size; }

Fl_Color Log::getColor() const { return _color; }

float Log::getSize() const { return _size; }


bool Log::contains(float playerPosition) const {
  if ((_leftCorner) <= playerPosition && playerPosition <= getRightCorner()) {
    return true;
  }
  return false;
}

void Log::move() {
  if (getRightCorner() >= 130) {
    _leftCorner = 0 - _size;
  } else {
    _leftCorner = _leftCorner + _speed * (0.2f);
  }
}

void Log::handleGame(Game *currentGame) {
  std::shared_ptr<Player> player = currentGame->getPlayer();
  player->setPosition(Position{player->getPosition().x + (_speed * 0.2f),
                               player->getPosition().y});
}

bool Log::hasImage() const { return false; }

Fl_PNG_Image *Log::getImage() const { return nullptr; }

bool Log::isVisible() const { return true; }

void Log::update() { return; }