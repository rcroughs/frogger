#include "IntInput.h"
#include "TextInput.h"

IntInput::IntInput(int x, int y) : TextInput(x, y) {
    image = new Fl_PNG_Image("assets/text_input.png");
}

void IntInput::addChar(char c) {
    if ('0' < c && c < '9') input += c;
}