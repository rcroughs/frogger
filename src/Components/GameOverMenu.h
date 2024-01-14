#ifndef _FROGGER_GAMEOVERMENU_H_
#define _FROGGER_GAMEOVERMENU_H_

#include "Button.h"
#include "../Driver.h"
#include <FL/Fl_PNG_Image.H>
#include <memory>
#include <vector>

class Driver;

class GameOverMenu {
public:
  GameOverMenu(Driver *driver, std::string filePath);
  ~GameOverMenu();

  // Getters
  [[nodiscard]] virtual Fl_PNG_Image *getImage() const;
  [[nodiscard]] virtual std::vector<std::shared_ptr<Button>> getButtons() const;

private:
  Driver *_driver;
  std::vector<std::shared_ptr<Button>> _buttons;
  Fl_PNG_Image *_image;
};

#endif // _FROGGER_WINNINGMENU_H_