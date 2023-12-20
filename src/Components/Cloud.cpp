#include "Cloud.h"
#include <iostream>
#include <time.h>

Cloud::Cloud(int y, bool goingRight)
    : base_y{y}, goingRight{goingRight}, x{}, y{} {
  image = new Fl_PNG_Image("res/cloud.png");
  if (image->fail() == Fl_Image::ERR_NO_IMAGE) {
    std::cout << "Image couln't load" << std::endl;
  }
  srand(clock());
  this->x = rand() % 700;
  srand(clock());
  this->y = base_y + (rand() % 150);
}

void Cloud::update() {
  if (goingRight) {
    if (x > 700) {
      x = -400;
      srand(clock());
      this->y = base_y + (rand() % 150);
    } else {
      x++;
    }
  } else {
    if ((x + 250) < 0) {
      x = 900;
      srand(clock());
      this->y = base_y + (rand() % 150);
    } else {
      x--;
    }
  }
}