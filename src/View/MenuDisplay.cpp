#include "MenuDisplay.h"
#include "../Components/Button.h"
#include "../Components/Cloud.h"
#include<vector>

void MenuDisplay::draw() {
    components->getBackground()->draw(0,0);
    components->getLogo()->draw(150,100);
    std::vector<Cloud>* clouds = components->getClouds();
    for (auto &cloud : *clouds) {
        cloud.getImage()->draw(cloud.getX(), cloud.getY());
        cloud.update();
    }
    std::vector<Button*> buttons = components->getButtons();
    for (auto &button : buttons) {
        button->getImage()->draw(button->getX(), button->getY());
    }
}