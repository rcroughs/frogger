#include "MainWindow.h"

void MainWindow::timer_handler(void* user_data) {
    MainWindow* o = static_cast<MainWindow*>(user_data);
    o->redraw();
    Fl::add_timeout(1.0 / 60.0, timer_handler, user_data);
}

int MainWindow::handle(int event) {
    switch (event) {
        case FL_MOVE:
            // Envoyer vers le controlleur
            return 1;
        case FL_PUSH:
            // Envoyer au controlleur
            return 1;
        case FL_KEYDOWN:
            // Envoyer au controlleur
            return 1;
        default:
            return 0;
    }
    return 0;
}

void MainWindow::draw() {
    renderer.draw();
}