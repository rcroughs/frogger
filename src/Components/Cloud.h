#ifndef FROGGER_CLOUD_H
#define FROGGER_CLOUD_H

#include "FL/Fl_PNG_Image.H"

class Cloud {
public:
  Cloud(int y, bool goingRight);
  int getX() { return x; }
  int getY() { return y; }
  Fl_PNG_Image *getImage() { return image; };
  void update();

private:
  int x;
  int base_y;
  int y;
  Fl_PNG_Image *image;
  bool goingRight;

};

#endif // FROGGER_CLOUD_H
