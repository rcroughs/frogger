#ifndef _FROGGER_ADDMAPMENU_H_
#define _FROGGER_ADDMAPMENU_H_

#include "TextInput.h"
#include "Button.h"
#include <FL/Fl_PNG_Image.H>
#include <memory>
#include <string>
#include <vector>

class AddMapMenu {
public:
  AddMapMenu();
  Fl_PNG_Image *getImage() const { return image; }
  std::vector<std::shared_ptr<TextInput>> getTextInputs() const { return _textInput; }
  bool isOpen() const { return _isOpen; }
  void changeState() { _isOpen = !_isOpen; }
  std::vector<std::shared_ptr<Button>> getButtons() const { return _buttons; }

private:
    Fl_PNG_Image *image;
    std::vector<std::shared_ptr<TextInput>> _textInput;
    std::vector<std::shared_ptr<Button>> _buttons;
    bool _isOpen;
};


#endif // _FROGGER_ADDMAPMENU_H_