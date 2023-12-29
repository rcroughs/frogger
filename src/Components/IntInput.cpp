#include "IntInput.h"
#include "TextInput.h"

IntInput::IntInput(int x, int y, std::string label) : TextInput(x, y, label) {
    image = new Fl_PNG_Image("res/input.png");
}

void IntInput::addChar(char c) {
    if ('0' < c && c < '9') input += c;
}