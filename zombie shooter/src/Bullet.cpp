#include"Bullet.h"

Bullet::Bullet()
{
    if(!textureBullet.loadFromFile("data\\bullet.png"))
       throw std::invalid_argument("can't load bullet.png");
    bullet.setTexture(textureBullet);
    speed=0.4f;
    power=1;
}

void Bullet::addVal(double x,double y, double rotation,double shift)
{
    vx = -sin(( rotation * 3.141592) / 180.0f );
    vy = cos(( rotation * 3.141592 ) / 180.0f );
    bullet.setPosition(sf::Vector2f(x+vx*shift,y+vy*shift));
}

void Bullet::changePosition()
{
    bullet.move(vx*speed,vy*speed);
}
