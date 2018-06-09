#include"SetOfBullets.h"

void SetOfBullets::changePosition()
{
    for(int i=0;i<setOfBullets.size();i++)
        setOfBullets[i]->changePosition();
}
std::vector<sf::Sprite*> SetOfBullets::onlySprite()
{
    std::vector<sf::Sprite*> v;
    for(int i=0;i<setOfBullets.size();i++)
        v.push_back(&setOfBullets[i]->bullet);
    return v;
}


 void SetOfBullets::deleteCollidingElements(std::vector<int>v)
 {
    std::vector<bool> vis;
    vis.resize(setOfBullets.size(),false);
    for(int i=0;i<v.size();i++)
    {
        vis[v[i]]=true;
    }

    for(int i=0;i<setOfBullets.size();i++)
    {
        if(setOfBullets.size()>i && vis[i])
        {
            delete setOfBullets[i];
            setOfBullets.erase(setOfBullets.begin()+i);
        }
    }
}

void SetOfBullets::checkIfOutsideOfMap()
{
    for(int i=0;i<setOfBullets.size();i++)
    {
        double x=setOfBullets[i]->bullet.getPosition().x;
        double y=setOfBullets[i]->bullet.getPosition().y;
        if(y < 0 || x < 0 || x > (double)gameWindowWidth || y > (double)gameWindowHeight )
        {
            delete setOfBullets[i];
            setOfBullets.erase(setOfBullets.begin()+i);
        }
    }

}

void SetOfBullets::addBullet(double x,double y,double rotation,double shift)
{
    Bullet *nBullet = new Bullet();
    nBullet->addVal(x,y,rotation,shift);
    setOfBullets.push_back(nBullet);
}


