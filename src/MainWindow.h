////////// Main Window Header File - MainWindow.h //////////
// Description: This class is responsible for the main window of the game.
// Inherit from: Fl_Window (FLTK), and overrides the draw() and handle() methods.
// Constructor takes: void
////////// FROGGER ////////////////////////////////////////

#ifndef FROGGER_SRC_MAIN_WINDOW_H
#define FROGGER_SRC_MAIN_WINDOW_H

#include "Driver.h"
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

class MainWindow : public Fl_Window {
public:
  MainWindow();

  /*
   * Struct to store a window position
   */
  struct ScreenPosition {
    int x;
    int y;
  };

  /*
   * This function is called every callback of the timer.
   * param user_data: a pointer to the MainWindow object.
   * return: void
   */
  static void timerHandler(void *user_data);

  /*
   * This function handles the events of the window.
   * param event: the event to handle.
   * return: 1 if the event was handled, 0 otherwise.
   */
  int handle(int event) override;

  /*
   * This function draws the window.
   * return: void
   */
  void draw() override;

  /*
   * This function returns the center position of the window.
   * return: the center position of the window.
   */
  ScreenPosition getCenterPosition() const;

private:
  Driver _driver;
  constexpr static int _timerInterval = 1.0 / 60.0;
  constexpr static int _width = 700;
  constexpr static int _height = 750;
  constexpr static char _title[] = "Frogger";
};

#endif // FROGGER_SRC_MAIN_WINDOW_H