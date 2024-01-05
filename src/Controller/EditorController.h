#ifndef SRC_EDITORCONTROLLER_H
#define SRC_EDITORCONTROLLER_H

#include "../Model/Game.h"
#include "../Model/GameEditor.h"
#include "Controller.h"
#include "array"
#include "vector"
#include <memory>

class GameEditor;

class EditorController : public Controller {
public:
  EditorController(std::shared_ptr<GameEditor> editor);

  virtual void mouseMove(short loc_x, short loc_y) override;
  virtual void mouseClick(short loc_x, short loc_y) override;
  virtual void keyPressed(int keycode) override;
  virtual void keyReleased(int keycode) override;
  virtual void updateMovement() override;
  virtual void mouseRelease(short loc_x, short loc_y) override;
  
private:
  std::shared_ptr<GameEditor> _editor;
};

#endif // SRC_EDITORCONTROLLER_H
