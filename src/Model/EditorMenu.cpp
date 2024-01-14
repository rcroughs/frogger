#include "EditorMenu.h"

#include "../Components/Buttons/DirectionButton.h"
#include "../Components/Buttons/PropButton.h"
#include "../Components/Buttons/RoadButton.h"
#include "../Components/Buttons/SideWalkButton.h"
#include "../Components/Buttons/SpeedButton.h"
#include "../Components/Buttons/WaterButton.h"
#include "../Driver.h"
#include <memory>

EditorMenu::EditorMenu(Driver* driver) : _driver{driver} {
    // Premier display de selection --> choix des environements
    _buttons.push_back(std::make_shared<WaterButton>((700/6)-23, 700, driver));
    _buttons.push_back(std::make_shared<RoadButton>((700/2)-23, 700, driver));
    _buttons.push_back(std::make_shared<SideWalkButton>(2 * (700/3) + (700/3)/2 -23, 700, driver));
    // Deuxième display de selection --> Vitesse (Eau & Road)
    _buttons.push_back(std::make_shared<SpeedButton>(((350/3)/2)-23, 0, driver, 0));         // Vitesse X1
    _buttons.push_back(std::make_shared<SpeedButton>((((350/3)/2) * 3) -23, 0, driver, 1));  // Vitesse X2
    _buttons.push_back(std::make_shared<SpeedButton>((((350/3)/2) * 5) -23, 0, driver, 2));  // Vitesse X3
    // Troisième display potentiel --> Water --> Log (0) & Turtle (1)
    _buttons.push_back(std::make_shared<PropButton>(350 + ((350/4)-23), 0, driver, 0));
    _buttons.push_back(std::make_shared<PropButton>(525 + ((175/2)-23), 0, driver, 1));
    // Quatrième display potentiel --> Road --> Left (0) & Right (1)
    _buttons.push_back(std::make_shared<DirectionButton>(350 + ((350/4)-23), 0, driver, 0));
    _buttons.push_back(std::make_shared<DirectionButton>(525 + ((175/2)-23), 0, driver, 1));
}

std::vector<std::shared_ptr<Button>> EditorMenu::getButtons() const {
    return _buttons;
}