#include "MainWindow.h"

void MainWindow::timer_handler(void* user_data) {
    MainWindow* o = static_cast<MainWindow*>(user_data);
    o->redraw();
    Fl::add_timeout(1.0 / 60.0, timer_handler, user_data);
}

int MainWindow::handle(int event) {
    switch (event) {
        case FL_MOVE:
            controller.mouseMove(Fl::event_x(), Fl::event_y());
            return 1;
        case FL_PUSH:
            controller.mouseClick(Fl::event_x(), Fl::event_y());
            return 1;
        case FL_KEYDOWN:
            controller.keyPressed(Fl::event_key());
            return 1;
        case FL_KEYUP:
            controller.keyReleased(Fl::event_key());
            return 1;
        default:
            return 0;
    }
    return 0;
}

void MainWindow::draw() {
    Fl_Window::draw();
    if (game.isRunning()) {
        controller.updateMovement();
        game.update();
    }
    renderer.draw();
}