#ifndef FROGGER_CLOUD_H
#define FROGGER_CLOUD_H

#include "FL/Fl_PNG_Image.H"

class Cloud {
public:
  Cloud(int y, bool goingRight);
  ~Cloud();

  [[nodiscard]] virtual int getX() const;
  [[nodiscard]] virtual int getY() const;
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const;

  void update();

private:
  int _x;
  int _base_y;
  int _y;
  Fl_PNG_Image *_image;
  bool _goingRight;
};

#endif // FROGGER_CLOUD_H
