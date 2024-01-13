#ifndef FROGGER_MENU_H
#define FROGGER_MENU_H

#include "../Components/Button.h"
#include "../Driver.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>
#include <vector>

class Driver;

class GameMenu {
public:
  GameMenu(int x, int y, Driver *driver);
  ~GameMenu();
  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;
  [[nodiscard]] std::vector<std::shared_ptr<Button>> getButtons() const;
  [[nodiscard]] std::shared_ptr<Fl_PNG_Image> getImage() const;
  [[nodiscard]] bool isOpen() const;
  void triggerMenu();

private:
  const int _x;
  const int _y;
  std::vector<std::shared_ptr<Button>> _buttons;
  std::shared_ptr<Fl_PNG_Image> _image;
  Driver *_driver;
  bool _isOpen;
};

#endif // FROGGER_MENU_H
