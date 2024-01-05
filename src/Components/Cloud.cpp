#include "Cloud.h"
#include <iostream>
#include <time.h>

Cloud::Cloud(int y, bool goingRight)
    : _base_y{y}, _goingRight{goingRight} {
  _image = new Fl_PNG_Image("res/cloud.png");
  if (_image->fail() == Fl_Image::ERR_NO_IMAGE) {
    std::cout << "Image couln't load" << std::endl;
  }
  srand(clock());
  this->_x = rand() % 700;
  srand(clock());
  this->_y = _base_y + (rand() % 150);
}

Cloud::~Cloud() { delete _image; }

int Cloud::getX() const { return _x; }

int Cloud::getY() const { return _y; }

Fl_PNG_Image *Cloud::getImage() const { return _image; };

void Cloud::update() {
  if (_goingRight) {
    if (_x > 700) {
      _x = -400;
      srand(clock());
      this->_y = _base_y + (rand() % 150);
    } else {
      _x++;
    }
  } else {
    if ((_x + 250) < 0) {
      _x = 900;
      srand(clock());
      this->_y = _base_y + (rand() % 150);
    } else {
      _x--;
    }
  }
}