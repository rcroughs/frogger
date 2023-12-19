#include "EditorRenderer.h"
#include "iostream"

class button;


void EditorRenderer::draw() {
    // Draw background
    for (int i = 0; i<13; i++) {
        Fl_Color* color = getEditor()->getColor(i);
        if (editor->getCurrentRow() == i) {
            color = new Fl_Color(FL_YELLOW);
        }
        fl_draw_box(FL_FLAT_BOX, 0, (height - (height / 13.0f)) - (i * (height / 13.0)), width, int(float(height) / 13.0f), *color);
        fl_frame("AAAA", 0, (width - (height / 13.0f)) - (i * (height / 13.0)), width, int(float(height) / 13.0f));

    }
    // Draw Buttons
    for (auto &button : editor->getMenu()->getButtons()) {
        if (button->isDisplayed()) {
            button->getImage()->draw(button->getX(), button->getY(), 46, 46);
        }
    }
}
