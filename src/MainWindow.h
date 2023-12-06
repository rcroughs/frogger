#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "Driver.h"


class MainWindow : public Fl_Window {
private:
    Driver driver;
public:
    MainWindow() : Fl_Window(700, 750, 700, 750, "Frogger"), driver{} {
        Fl::add_timeout(1.0 / 60.0, timer_handler, this);
        resizable(this);
    }
    static void timer_handler(void* user_data);
    int handle(int event) override;
    void draw() override;
};

#endif