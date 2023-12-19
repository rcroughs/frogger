#ifndef SRC_GAMEEDITOR_H
#define SRC_GAMEEDITOR_H

#include "../Driver.h"
#include "../Model/Environment.h"
#include "EditorMenu.h"
#include "Game.h"

class Driver;
class EditorMenu;
class Game;

class GameEditor {
private:
    Game* game;
    Driver* driver;
    EditorMenu* menu;

    int enviNumber; // Doit être 12 pour lancer le jeu

    enum ENVIRONMENT {
        ROAD,
        SIDEWALK,
        WATER
    };

    std::vector<Fl_Color*> colors;
    int WINDOW_HEIGHT;
    int WINDOW_WIDTH;

    // Road Parameters
    char RoadCirculation{'\0'};
    float RoadSpeedLimit{0};

    // Water Parameters --> PropId does not have to be modified, it will be used for generateProps(id) and
    // CAN be modified
    float WaterFlow{0};
    short WaterPropId{0};

    // Mouse on row
    int currentRow;


public:
    GameEditor(Driver* driver, int width, int height);

    // IMPORTANT GETTERS
    virtual Driver* getDriver() {return driver;}
    virtual EditorMenu* getMenu() {return menu;}
    virtual Game* getGame() {return game;}

    // Information about the environment's colors (even when not already configured)
    virtual Fl_Color* getColor(short index) {return colors.at(index);}
    virtual std::vector<Fl_Color*> getColors() {return colors;}
    virtual void setColor(Fl_Color* color) {colors.at(getCurrentRow()) = color;}

    // Add & Delete & Get an environment
    virtual void addEnvironment(int index, short id);
    virtual void deleteEnvironment(int index);
    Environment* getEnvironment(int index);

    // Add a specific environment, use by addEnvironement()
    virtual void addRoad(int index);
    virtual void addSideWalk(int index);
    virtual void addWater(int index);

    // Parameters --> Setters and Getters
    virtual void modifyRoadCirculation(char new_circulation) {RoadCirculation = new_circulation;}
    virtual void modifyRoadSpeedLimit(float new_speedLimit) {RoadSpeedLimit = new_speedLimit;}
    virtual void modifyWaterFlow(float new_flow) {WaterFlow = new_flow;}
    virtual void modifyWaterPropId(short new_prop_id) {WaterPropId = new_prop_id;}
    virtual char getRoadCirculation() {return RoadCirculation;}
    virtual float getRoadSpeedLimit() {return RoadSpeedLimit;}
    virtual float getWaterFlow() {return WaterFlow;}
    virtual short getWaterPropId() {return WaterPropId;}

    // Information about the already existing environments
    virtual int getEnviNumber() {return enviNumber;}
    virtual void setEnviNumber(int new_number) {enviNumber = new_number;}
    virtual void increaseEnviNumber() {enviNumber++;}
    virtual void decreaseEnviNumber() {enviNumber--;}

    // Information about the mouse's position --> selection
    virtual void changeCurrentRow(int new_row) {currentRow = new_row;}
    virtual int getCurrentRow() {return currentRow;}

    // Shows/Hides Environment selection buttons
    virtual void triggerEnvironmentButton();

    // Getters for the windows's dimensions
    virtual int getWindowWidth() {return WINDOW_WIDTH;}
    virtual int getWindowHeight() {return WINDOW_HEIGHT;}
};

#endif //SRC_GAMEEDITOR_H
