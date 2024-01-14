////////// Editor Renderer - src/View/EditorRenderer.h //////////
// Description: This class renders the editor.
// Constructor takes: An editor and the window size.
////////// FROGGER ///////////////////////////////////

#ifndef _FROGGER_EDITORRENDERER_H
#define _FROGGER_EDITORRENDERER_H

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

  // Getters
  [[nodiscard]] virtual std::shared_ptr<GameEditor> getEditor() const;

  // Draw the editor
  virtual void draw() const override;

private:
  std::shared_ptr<GameEditor> _editor;
  int _width;
  int _height;
};

#endif // _FROGGER_EDITORRENDERER_H
