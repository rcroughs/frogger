#include "QuitButton.h"

QuitButton::QuitButton(int x, int y) : x{x}, y{y} {
    image = new Fl_PNG_Image("res/quit.png");
}

bool QuitButton::contains(int x, int y) {
    if (this->x < x && x < this->x + 200 && y < this->y + 100 && this->y < y) return true;
    return false;
}
void QuitButton::onClick() {
    exit(1);
}
