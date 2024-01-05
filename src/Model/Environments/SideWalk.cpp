#include "SideWalk.h"
#include <memory>

SideWalk::SideWalk() : _color{FL_BLACK}, _props{}, _id{"4"} {}

Fl_Color SideWalk::getColor() const { return _color; }

void SideWalk::setColor(Fl_Color new_color) { _color = new_color; }

std::vector<std::shared_ptr<Prop>> SideWalk::getProps() const { return _props; }

void SideWalk::handleGame(Game *currentGame) { static_cast<void>(currentGame); }

void SideWalk::updateProps() {}

void SideWalk::generateProps(short id) { static_cast<void>(id); }

std::string SideWalk::getId() const { return _id; }