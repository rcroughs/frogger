#ifndef _FROGGER_LEVEL_SELECTOR_H_
#define _FROGGER_LEVEL_SELECTOR_H_

#include <FL/Fl.H>
#include <memory>
#include <vector>

#include "Buttons/LevelButton.h"
#include "Buttons/MenuButton.h"
#include "../Driver.h"

class LevelButton;
class Driver;
class MenuButton;

class LevelSelector  {
public:
  LevelSelector(Driver* driver);
  ~LevelSelector();

  // Getters
  [[nodiscard]] virtual std::vector<std::shared_ptr<LevelButton>> getButtons() const;
  [[nodiscard]] virtual std::shared_ptr<MenuButton> getMenuButton() const;
  [[nodiscard]] virtual Fl_PNG_Image *getBg() const;

  // Scroll up and down
  virtual void scrollUp();
  virtual void scrollDown();

private:
  std::vector<std::string> getFiles(std::string path);
  std::vector<std::shared_ptr<LevelButton>> _buttons;
  std::shared_ptr<MenuButton> _menuButton;
  Driver* _driver;
  Fl_PNG_Image *_bg;
};

#endif // _FROGGER_LEVEL_SELECTOR_H_