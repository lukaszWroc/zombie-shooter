
#ifndef PLAYER_H

#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"GameSettings.h"
#include <stdexcept>

class Player{
private:
    int strength;
    double speed;
    sf::Texture texturePlayer;
public:
    int life;
    sf::Sprite player;

    Player();
    std::vector<sf::Sprite*> onlySprite();
    void changePosition(char c);
};


#endif // PLAYER_H
