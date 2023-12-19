#ifndef SRC_EDITORRENDERER_H
#define SRC_EDITORRENDERER_H

#include "../Model/GameEditor.h"
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/fl_draw.H"
#include "View.h"

class GameEditor;

class EditorRenderer : public View {
private:
    GameEditor* editor;
    int width;
    int height;
    // Add driver ?
public:
    EditorRenderer(GameEditor* editor, int width, int height) : editor{editor}, width{width}, height{height} {}

    virtual GameEditor* getEditor() {return editor;}

    virtual void draw();
};

#endif //SRC_EDITORRENDERER_H
