#ifndef SRC_EDITORCONTROLLER_H
#define SRC_EDITORCONTROLLER_H

#include "../Model/Game.h"
#include "array"
#include "vector"
#include "Controller.h"
#include "../Model/GameEditor.h"

class GameEditor;

class EditorController : public Controller{
private:
    GameEditor* editor;
public:
    EditorController(GameEditor* editor) : editor{editor} {}

    virtual void mouseMove(short loc_x, short loc_y) override;
    virtual void mouseClick(short loc_x, short loc_y) override;
    virtual void keyPressed(int keycode) override {};
    virtual void keyReleased(int keycode) override {};
    virtual void updateMovement() override {};
    virtual void mouseRelease(short loc_x, short loc_y) {}
};

#endif //SRC_EDITORCONTROLLER_H
