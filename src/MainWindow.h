#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "View/GameRenderer.h"
#include "Model/Game.h"
#include "Controller/GameController.h"


class MainWindow : public Fl_Window {
private:
    Game game;
    GameRenderer renderer;
    GameController controller;
public:
    MainWindow() : Fl_Window(700, 700, 700, 700, "Frogger"), game{Player({0,0}, down), Map()}, renderer{&this->game, 700,700},
                   controller{&this->game} {
        Fl::add_timeout(1.0 / 60.0, timer_handler, this);
        resizable(this);
    }
    static void timer_handler(void* user_data);
    int handle(int event) override;
    void draw() override;
};
