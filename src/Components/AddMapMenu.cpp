#include "AddMapMenu.h"

#include "Buttons/AddMapButton.h"

AddMapMenu::AddMapMenu() : _isOpen(false) {
  image = new Fl_PNG_Image("res/addmenu.png");
  _textInput.push_back(std::make_shared<TextInput>(100, 200, "Map Name"));
  _textInput.push_back(std::make_shared<TextInput>(100, 300, "Author"));
  _textInput.push_back(std::make_shared<TextInput>(100 ,400, "Map Code"));
  _buttons.push_back(std::make_shared<AddMapButton>(400, 0, _textInput[0], _textInput[1], _textInput[2]));
}