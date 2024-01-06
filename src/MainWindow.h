#ifndef FROGGER_SRC_MAIN_WINDOW_H
#define FROGGER_SRC_MAIN_WINDOW_H

#include "Driver.h"
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

class MainWindow : public Fl_Window {
public:
  MainWindow();

  struct ScreenPosition {
    int x;
    int y;
  };

  static void timerHandler(void *user_data);
  int handle(int event) override;
  void draw() override;
  ScreenPosition getCenterPosition() const;

private:
  Driver _driver;
  constexpr const static int _timerInterval = 1.0 / 60.0;
  constexpr const static int _width = 700;
  constexpr const static int _height = 750;
  constexpr const static char _title[] = "Frogger";
};

#endif // FROGGER_SRC_MAIN_WINDOW_H