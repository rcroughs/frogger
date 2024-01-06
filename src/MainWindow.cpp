#include "MainWindow.h"
#include <FL/Fl.H>

MainWindow::MainWindow()
    : Fl_Window(getCenterPosition().x, getCenterPosition().y, _width, _height,
                _title),
      _driver{} {
  Fl::add_timeout(_timerInterval, timerHandler, this);
  resizable(this);
}

void MainWindow::timerHandler(void *user_data) {
  MainWindow *o = static_cast<MainWindow *>(user_data);
  o->redraw();
  Fl::add_timeout(1.0 / 60.0, timerHandler, user_data);
}

int MainWindow::handle(int event) {
  switch (event) {
  case FL_MOVE:
    _driver.mouseMove(Fl::event_x(), Fl::event_y());
    return 1;
  case FL_PUSH:
    _driver.mouseClick(Fl::event_x(), Fl::event_y());
    return 1;
  case FL_KEYDOWN:
    _driver.keyPressed(Fl::event_key());
    return 1;
  case FL_KEYUP:
    _driver.keyReleased(Fl::event_key());
    return 1;
  default:
    return 0;
  }
  return 0;
}

void MainWindow::draw() {
  Fl_Window::draw();
  _driver.refresh();
}

MainWindow::ScreenPosition MainWindow::getCenterPosition() const {
  return ScreenPosition{static_cast<int>(Fl::w() / 2 - _width / 2),
                        static_cast<int>(Fl::h() / 2 - h() / 2)};
}