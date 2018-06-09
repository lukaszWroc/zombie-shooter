#ifndef BULLET_H

#define BULLET_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include <stdexcept>
class Bullet{
private:
    sf::Texture textureBullet;
    int power;
    double speed;
    double vx,vy;
public:
    Bullet();
    sf::Sprite bullet;

    void addVal(double x,double y, double rotation,double shift);
    void changePosition();
};


#endif // BULLET_H
