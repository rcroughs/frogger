#include "PlayButton.h"

PlayButton::PlayButton(int x, int y) : x{x}, y{y} {
    image = new Fl_PNG_Image("res/play.png");
}