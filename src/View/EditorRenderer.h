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
  EditorRenderer(std::shared_ptr<GameEditor> editor, int width, int height);

  [[nodiscard]] virtual std::shared_ptr<GameEditor> getEditor() const;

  virtual void draw() const override;

private:
  std::shared_ptr<GameEditor> _editor;
  int _width;
  int _height;
};

#endif // SRC_EDITORRENDERER_H
