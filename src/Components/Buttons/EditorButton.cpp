#include "EditorButton.h"

EditorButton::EditorButton(int x, int y) : x{x}, y{y} {
    image = new Fl_PNG_Image("res/editor.png");
}

bool EditorButton::contains(int x, int y) {
    if (this->x < x && x < this->x + 200 && y < this->y + 100 && this->y < y) return true;
    return false;
}

void EditorButton::onClick() {
    exit(1);
}
