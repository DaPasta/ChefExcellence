#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Clock.hpp>
#include "gamescreen.hpp"
#include "mainmenuscreen.hpp"

class Game {
    private:
        bool isPlaying;

        sf::RenderWindow window;
        sf::View view;

        sf::Clock frameClock;

        //Screens
        static Screen *currentScreen;

        void update();
        void render();

    public:
        Game();
        void execute();

        static void setScreen(Screen *screen);

        static const int SCREEN_WIDTH;
        static const int SCREEN_HEIGHT;

        static GameScreen *gameScreen;
        static MainMenuScreen *mainMenuScreen;
};

#endif
