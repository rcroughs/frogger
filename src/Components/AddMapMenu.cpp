#include "AddMapMenu.h"

#include "Buttons/AddMapButton.h"
#include "Buttons/PasteButton.h"

AddMapMenu::AddMapMenu() : _isOpen(false) {
  image = new Fl_PNG_Image("res/addmenu.png");
  _textInput.push_back(std::make_shared<TextInput>(100, 200));
  _textInput.push_back(std::make_shared<TextInput>(100, 300));
  _textInput.push_back(std::make_shared<TextInput>(100 ,400));
  _buttons.push_back(std::make_shared<AddMapButton>(0, 0, _textInput[0], _textInput[1], _textInput[2]));
  _buttons.push_back(std::make_shared<PasteButton>(_textInput[2], 0, 0));
}