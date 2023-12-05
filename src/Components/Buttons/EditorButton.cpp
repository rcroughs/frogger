#include "EditorButton.h"

EditorButton::EditorButton(int x, int y) : x{x}, y{y} {
    image = new Fl_PNG_Image("res/editor.png");
}

void EditorButton::onClick() {
    exit(1);
}
