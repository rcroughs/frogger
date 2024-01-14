////////// Pause Menu Header File - src/Model/PauseMenu.h //////////
// Description: This class represents the pause menu.
// Constructor takes: A position and a pointer to the driver
////////// FROGGER ////////////////////////////////////////

#ifndef _FROGGER_MENU_H
#define _FROGGER_MENU_H

#include "../Components/Button.h"
#include "FL/Fl_PNG_Image.H"
#include <memory>
#include <vector>

// Forward declaration
class Driver;

class PauseMenu {
public:
  PauseMenu(int x, int y, Driver *driver);
  ~PauseMenu();

  // Getters and setters
  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;
  [[nodiscard]] std::vector<std::shared_ptr<Button>> getButtons() const;
  [[nodiscard]] std::shared_ptr<Fl_PNG_Image> getImage() const;
  [[nodiscard]] bool isOpen() const;

  // Trigger the menu (if open, close it and vice versa)
  void triggerMenu();

private:
  const int _x;
  const int _y;
  std::vector<std::shared_ptr<Button>> _buttons;
  std::shared_ptr<Fl_PNG_Image> _image;
  Driver *_driver;
  bool _isOpen;
};

#endif // _FROGGER_MENU_H
