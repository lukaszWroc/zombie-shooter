#include"Zombie.h"

Zombie::Zombie()
{
    reloadTime = sf::seconds(0.1f);
    clock.restart();
    index=0;
    maxIndex=9;
    life=4;
    speed = 0.0155f;
    strength=1;
    if( !textureZombie.loadFromFile("data\\zombie0.png") )
       throw std::invalid_argument("can't load zombie0.png");
    zombie.setTexture(textureZombie);
}

void Zombie::changePosition(double x,double y)
{
    zombie.setRotation( atan2(-y+zombie.getPosition().y,-x+zombie.getPosition().x) * 180.0f/3.14 + 90);
    double rotation=zombie.getRotation();
    double vx = -sin(( rotation * 3.141592) / 180.0f );
    double vy = cos(( rotation * 3.141592 ) / 180.0f );
    zombie.move(vx*speed,vy*speed);
}

int Zombie::dealDamage()
{

    if(index == maxIndex)
    {
        index = 0;
        return strength;
    }
    return 0;
}

void Zombie::setRightTexture(int x)
{
    if( !textureZombie.loadFromFile("data\\Zombie"+ intToString(x) + ".png") )
           throw std::invalid_argument("can't load zombie" + intToString(x) + ".png");
    zombie.setTexture(textureZombie);
}
