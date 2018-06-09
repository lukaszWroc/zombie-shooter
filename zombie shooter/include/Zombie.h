#ifndef ZOMBIE_H

#define ZOMBIE_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include"IntToString.h"
#include <stdexcept>

class Zombie{
private:
    int strength;
    double speed;
    sf::Texture textureZombie;
public:
    int index,maxIndex;
    sf::Clock clock;
    sf::Time reloadTime;
    sf::Sprite zombie;
    int life;

    Zombie();
    void changePosition(double x,double y);
    int dealDamage();
    void setRightTexture(int x);
};


#endif // ZOMBIE_H
