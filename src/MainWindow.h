#ifndef FROGGER_SRC_MAIN_WINDOW_H
#define FROGGER_SRC_MAIN_WINDOW_H

#include "Driver.h"
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

class MainWindow : public Fl_Window {
public:
  MainWindow() : Fl_Window(700, 750, 700, 750, "Frogger"), _driver{} {
    Fl::add_timeout(1.0 / 60.0, timerHandler, this);
    resizable(this);
  }
  static void timerHandler(void *user_data);
  int handle(int event) override;
  void draw() override;

private:
  Driver _driver;
};

#endif // FROGGER_SRC_MAIN_WINDOW_H