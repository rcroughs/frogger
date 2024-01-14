////////// Homescreen View Header File - src/View/ViewHomeScreen.h //////////
// Description: This class draw the homescreen.
// Constructor takes: void
////////// FROGGER ///////////////////////////////////

#ifndef _FROGGER_VIEWHOMESCREEN_H
#define _FROGGER_VIEWHOMESCREEN_H

#include "FL/Fl_PNG_Image.H"
#include "View.h"
#include <memory>

class ViewHomeScreen : public View {
public:
  ViewHomeScreen();

  // Draw the homescreen
  virtual void draw() const override;

private:
  std::shared_ptr<Fl_PNG_Image> _image;
};

#endif // _FROGGER_VIEWHOMESCREEN_H
