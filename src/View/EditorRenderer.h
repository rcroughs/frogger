#ifndef SRC_EDITORRENDERER_H
#define SRC_EDITORRENDERER_H

#include "../Model/GameEditor.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/fl_draw.H"
#include "View.h"
#include <memory>

class GameEditor;

class EditorRenderer : public View {
public:
  EditorRenderer(std::shared_ptr<GameEditor> editor, int width, int height)
      : _editor{std::move(editor)}, width{width}, height{height} {}

  virtual std::shared_ptr<GameEditor> getEditor() { return _editor; }

  virtual void draw();

private:
  std::shared_ptr<GameEditor> _editor;
  int width;
  int height;
};

#endif // SRC_EDITORRENDERER_H
