#include "MenuComponents.h"
#include "Fl/Fl_PNG_Image.H"
#include "Buttons/PlayButton.h"
#include "Buttons/QuitButton.h"
#include "Buttons/EditorButton.h"

MenuComponents::MenuComponents() {
    logo = new Fl_PNG_Image("res/title.png");
    bg = new Fl_PNG_Image("res/bg.png");
    clouds.push_back({ 0, false });
    clouds.push_back({ 150, true });
    buttons.push_back(new PlayButton(250, 300));
    buttons.push_back(new EditorButton(250, 420));
    buttons.push_back(new QuitButton(250, 540));
}

void MenuComponents::update() {
    for (auto &cloud : clouds) {
        cloud.update();
    }
}