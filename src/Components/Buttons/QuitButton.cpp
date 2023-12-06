#include "QuitButton.h"

QuitButton::QuitButton(int x, int y) : x{x}, y{y} {
    image = new Fl_PNG_Image("res/quit.png");
}

void QuitButton::onClick() {
    exit(1);
}
