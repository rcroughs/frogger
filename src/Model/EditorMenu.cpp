#include "EditorMenu.h"

#include "../Components/Buttons/DirectionButton.h"
#include "../Components/Buttons/PropButton.h"
#include "../Components/Buttons/RoadButton.h"
#include "../Components/Buttons/SideWalkButton.h"
#include "../Components/Buttons/SpeedButton.h"
#include "../Components/Buttons/WaterButton.h"
#include <memory>

EditorMenu::EditorMenu(Driver* driver) : driver{driver} {
    // Premier display de selection --> choix des environements
    buttons.push_back(new WaterButton((700/6)-23, 700, driver));
    buttons.push_back(new RoadButton((700/2)-23, 700, driver));
    buttons.push_back(new SideWalkButton(2 * (700/3) + (700/3)/2 -23, 700, driver));
    // Deuxième display de selection --> Vitesse (Eau & Road)
    buttons.push_back(new SpeedButton(((350/3)/2)-23, 0, driver, 0));         // Vitesse X1
    buttons.push_back(new SpeedButton((((350/3)/2) * 3) -23, 0, driver, 1));  // Vitesse X2
    buttons.push_back(new SpeedButton((((350/3)/2) * 5) -23, 0, driver, 2));  // Vitesse X3
    // Troisième display potentiel --> Water --> Log (0) & Turtle (1)
    buttons.push_back(new PropButton(350 + ((350/4)-23), 0, driver, 0));
    buttons.push_back(new PropButton(525 + ((175/2)-23), 0, driver, 1));
    // Quatrième display potentiel --> Road --> Left (0) & Right (1)
    buttons.push_back(new DirectionButton(350 + ((350/4)-23), 0, driver, 0));
    buttons.push_back(new DirectionButton(525 + ((175/2)-23), 0, driver, 1));
}

