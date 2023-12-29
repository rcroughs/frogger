#include "TextInput.h"

TextInput::TextInput(int x, int y, std::string label) : _x{x}, _y{y}, _isActive(false), label{label} {
  image = new Fl_PNG_Image("res/input.png");
}

Fl_PNG_Image *TextInput::getImage() const { return image; }

void TextInput::addChar(char c) {
  if ('0' < c && c < 'z')
    input += c;
}

void TextInput::removeChar() {
  if (input.length() > 0) {
    input.pop_back();
  }
}

std::string TextInput::getInput() { return input; }

void TextInput::pasteString(std::string str) { input = str; }

bool TextInput::isActive() { return _isActive; }

void TextInput::changeActivity() { _isActive = !_isActive; }

void TextInput::resetActivity() { _isActive = false; }

bool TextInput::contains(int x, int y) {
  if (x >= _x && x <= _x + 600 && y >= _y && y <= _y + 60)
    return true;
  return false;
}

bool TextInput::isEmpty() { return input.length() == 0; }

std::string TextInput::getLabel() { return label; }
