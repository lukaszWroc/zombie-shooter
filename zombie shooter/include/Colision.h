#ifndef COLISION_H

#define COLISION_H

#include<SFML/Graphics.hpp>
#include<vector>

std::vector< std::pair<int,int> > colision(std::vector<sf::Sprite*> v1,std::vector<sf::Sprite*> v2);
std::vector<int> colisionFirstElement(std::vector< std::pair<int,int> > v);
std::vector<int> colisionSecondElement(std::vector< std::pair<int,int> > v);

#endif // COLISION_H
