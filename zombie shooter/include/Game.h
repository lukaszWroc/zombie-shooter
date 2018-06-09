#ifndef GAME_H

#define GAME_H

#include<SFML/Graphics.hpp>
#include<string>
#include"Engine.h"
#include"GameSettings.h"

class Game
{
    public:
        Game();
        void runGame();
        sf::Text title;
        sf::Text menuOptionsTableText[2];
        void displayMenu();
        void displayGame();
    private:
        enum GameState {MENU,GAME,END};
        GameState state;
        sf::RenderWindow gameWindow;
        sf::Font font;
};


#endif // GAME_H
