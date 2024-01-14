#include "EditorRenderer.h"

#include "../Model/EditorMenu.h"

class button;

EditorRenderer::EditorRenderer(std::shared_ptr<GameEditor> editor, int width,
                               int height)
    : _editor{std::move(editor)}, _width{width}, _height{height} {}

std::shared_ptr<GameEditor> EditorRenderer::getEditor() const {
  return _editor;
}

void EditorRenderer::draw() const {
  // Draw background
  for (int i = 0; i < 13; i++) {
    Fl_Color *color = getEditor()->getColor(i);
    if (_editor->getCurrentRow() == i) {
      color = new Fl_Color(FL_YELLOW);
    }
    fl_draw_box(FL_FLAT_BOX, 0,
                (_height - (_height / 13.0f)) - (i * (_height / 13.0)), _width,
                int(float(_height) / 13.0f), *color);
    fl_frame("AAAA", 0, (_width - (_height / 13.0f)) - (i * (_height / 13.0)),
             _width, int(float(_height) / 13.0f));
  }
  // Draws Buttons
  for (auto &button : _editor->getMenu()->getButtons()) {
    if (button->isDisplayed()) {
      button->getImage()->draw(button->getX(), button->getY(), 46, 46);
    }
  }

  if (_editor->isPaused()) {
    _editor->getPauseMenu()->getImage()->draw(_editor->getPauseMenu()->getX(),
                                              _editor->getPauseMenu()->getY());
    for (auto &button : _editor->getPauseMenu()->getButtons()) {
      if (button->isDisplayed()) {
        button->getImage()->draw(button->getX(), button->getY());
      }
    }
  }
  // Handles time out
  _editor->handleTimeOut();
}
