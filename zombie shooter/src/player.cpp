#include"Player.h"

Player::Player()
{

    life=100;
    speed = 3.0f;
    strength=1;
    if( !texturePlayer.loadFromFile("data\\player.png") )
       throw std::invalid_argument("can't load player.png");

    player.setTexture(texturePlayer);
    player.setPosition(gameWindowWidth/2,gameWindowHeight/2);
    player.setOrigin(20,20);
}

void Player::changePosition(char c)
{
    double direction=180;
    if(c == 'S')
        direction=0;
    if(c == 'A')
        direction=90;
    if(c == 'D')
        direction=270;
    double rotation = player.getRotation() + direction;
	double vx = sin(( rotation * 3.141592) / 180.0f );
	double vy = -cos(( rotation * 3.141592) / 180.0f );
	player.move(speed*vx,speed*vy);
}

std::vector<sf::Sprite*> Player::onlySprite()
{
    std::vector<sf::Sprite*> v;
    v.push_back(&player);
    return v;
}


