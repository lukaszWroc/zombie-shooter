#include"Colision.h"

std::vector< std::pair<int,int> > colision(std::vector<sf::Sprite*> v1,std::vector<sf::Sprite*> v2)
{
    std::vector< std::pair<int,int> > colisionPair;

    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v2.size();j++)
        {
            if(v1[i]->getGlobalBounds().intersects(v2[j]->getGlobalBounds()))
            {
                colisionPair.push_back(std::make_pair(i,j));
            }
        }
    }
    return colisionPair;
}

std::vector<int> colisionFirstElement(std::vector< std::pair<int,int> > v)
{
    std::vector<int> nV;
    for(int i=0;i<v.size();i++)
        nV.push_back(v[i].first);
    return nV;
}


std::vector<int> colisionSecondElement(std::vector< std::pair<int,int> > v)
{
    std::vector<int> nV;
    for(int i=0;i<v.size();i++)
        nV.push_back(v[i].second);
    return nV;
}
