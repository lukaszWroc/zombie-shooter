#ifndef SET_OF_BULLETS_H

#define SET_OF_BULLETS_H

#include"Bullet.h"
#include<vector>
#include"GameSettings.h"
#include<SFML/Graphics.hpp>

class SetOfBullets{
public:
    std::vector<Bullet*>setOfBullets;
    void changePosition();
    std::vector<sf::Sprite*> onlySprite();
    void deleteCollidingElements(std::vector<int>v);
    void checkIfOutsideOfMap();
    void addBullet(double x,double y,double rotation,double shift);
};


#endif // SET_OF_BULLETS_H
