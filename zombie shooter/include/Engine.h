#ifndef ENGINE_H

#define ENGINE_H

#include<SFML/Graphics.hpp>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
#include"SetOfBullets.h"
#include"Bullet.h"
#include"Zombie.h"
#include"SetOfZombies.h"
#include"Colision.h"
#include"GameSettings.h"
#include"IntToString.h"
#include"Player.h"

class Engine
{
public:
    Engine(sf::RenderWindow &_nGameWindow);
    bool runEngine();
private:
    std::string waveString;
    sf::Text waveText;
    std::string lifeString;
    sf::Text lifeText;
    int wave[8] = {10,12,14,17,20,24,28,30};
    int waveCNT=0,waveMax=8;
    sf::RenderWindow *nGameWindow;
    SetOfBullets *nSetOfBullets;
    SetOfZombies *nSetOfZombies;
    Player *nPlayer;
    sf::Font font;
    enum EngineState {RUN,PAUSE,BACK_W0N,BACK_LOSE,END,END2};
    enum EngineState state;

    void run();
    void backToMenu(std::string s);
    void pause();
    void changeWaveAndLife();
};

#endif // ENGINE_H
