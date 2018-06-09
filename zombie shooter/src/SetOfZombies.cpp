#include"SetOfZombies.h"

void SetOfZombies::changePosition(double x,double y)
{
    for(int i=0;i<setOfZombies.size();i++)
    {
        setOfZombies[i]->changePosition(x,y);
    }
}
std::vector<sf::Sprite*> SetOfZombies::onlySprite()
{
    std::vector<sf::Sprite*> v;
    for(int i=0;i<setOfZombies.size();i++)
        v.push_back(&setOfZombies[i]->zombie);
    return v;
}
 void SetOfZombies::deleteCollidingElements(std::vector<int>v)
 {
    std::vector<bool>vis;
    vis.resize(setOfZombies.size(),false);

    for(int i=0;i<v.size();i++)
    {
        vis[v[i]]=true;
    }
    for(int i=0;i<setOfZombies.size();i++)
    {
        if(setOfZombies.size()>i && vis[i])
        {
            delete setOfZombies[i];
            setOfZombies.erase(setOfZombies.begin()+i);
        }
    }
 }

void SetOfZombies::randomZombies(int n)
{
    srand(time(NULL));
    for(int i=0;i<n;i++){
        Zombie *b = new Zombie();
        double x=rand()%1400-100;
        double y = sqrt(750*750 - (600-x) *(600 -x));
        int z=rand()%2;
        if(z==1)
            y=-y;
        y+=300;

        b->zombie.setPosition(x,y);
        setOfZombies.push_back(b);
    }
}


int SetOfZombies::dealDamage(std::vector<int> v)
{
    std::vector<bool> vis;
    vis.resize(setOfZombies.size(),false);
    int damage = 0;
    for(int i=0;i<v.size();i++)
    {
        vis[v[i]]=true;
        if(setOfZombies[v[i]]->clock.getElapsedTime() >=  setOfZombies[v[i]]->reloadTime)
        {
            setOfZombies[v[i]]->clock.restart();
            setOfZombies[v[i]]->index++;
        }
        if(setOfZombies[v[i]]->index == setOfZombies[v[i]]->maxIndex)
        {
            damage += setOfZombies[v[i]]->dealDamage();
            setOfZombies[v[i]]->index=0;
        }
        setOfZombies[v[i]]->setRightTexture(setOfZombies[v[i]]->index);
    }
    for(int i=0;i<setOfZombies.size();i++)
    {
        if(!vis[i] && setOfZombies[i]->index!=0)
        {
            setOfZombies[i]->index=0;
            setOfZombies[i]->setRightTexture(0);
            setOfZombies[i]->clock.restart();
        }
    }
    return damage;
}



