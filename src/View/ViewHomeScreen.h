#ifndef FROGGER_VIEWHOMESCREEN_H
#define FROGGER_VIEWHOMESCREEN_H

#include "FL/Fl_PNG_Image.H"
#include "View.h"
#include <memory>

class ViewHomeScreen : public View {
public:
  ViewHomeScreen();
  virtual void draw() const override;

private:
  std::shared_ptr<Fl_PNG_Image> _image;
};

#endif // FROGGER_VIEWHOMESCREEN_H
