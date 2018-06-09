#ifndef SET_OF_ZOMBIES_H

#define SET_OF_ZOMBIES_H

#include<vector>
#include"Zombie.h"
#include"IntToString.h"

class SetOfZombies{

public:
    std::vector<Zombie*>setOfZombies;
    void changePosition(double x,double y);
    void randomZombies(int n);
    std::vector<sf::Sprite*> onlySprite();
    void deleteCollidingElements(std::vector<int>v);
    int dealDamage(std::vector<int> v);

};


#endif // SET_OF_ZOMBIES_H
