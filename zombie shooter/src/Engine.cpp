#include"Engine.h"

Engine::Engine(sf::RenderWindow &_nGameWindow)
{
    state = RUN;
    nGameWindow=&_nGameWindow;


    if(!font.loadFromFile("data\\arial.ttf"))
       throw std::invalid_argument("can't load arial.ttf");

    nSetOfBullets = new SetOfBullets();
    nSetOfZombies = new SetOfZombies();
    nPlayer = new Player();

    waveText.setFont(font);
    waveString="WAVE: ";
    waveText.setCharacterSize(20);
    waveText.setPosition(50,50);

    lifeText.setFont(font);
    lifeString="LIFE: ";
    lifeText.setCharacterSize(20);
    lifeText.setPosition(50,100);
}

bool Engine::runEngine()
{
    while(state!=END && state!=END2)
    {
        switch(state)
        {
            case PAUSE:
                pause();
                break;
            case RUN:
                run();
                break;
            case BACK_W0N:
                backToMenu("YOU WON!");
                break;
            case BACK_LOSE:
                backToMenu("YOU LOSE!");
                break;
        }
    }
    if(state == END2)
        return true;
    return false;
}


void Engine::run()
{
    sf::Texture backgroudTexture;
    if(!backgroudTexture.loadFromFile("data\\background.png"))
       throw std::invalid_argument("can't load background.png");
    sf::Sprite backgroudSprite;
    backgroudSprite.setTexture(backgroudTexture);

    while(state == RUN)
    {

        if(nSetOfZombies->setOfZombies.size() == 0)
        {
            if(waveMax-1>waveCNT)
                nSetOfZombies->randomZombies(wave[waveCNT++]);
            else
                state = BACK_W0N;
        }
        if(nPlayer->life < 0)
            state = BACK_LOSE;
        sf::Event event;
        sf::Vector2f mouse(sf::Mouse::getPosition(*nGameWindow));
        while(nGameWindow->pollEvent(event))
        {
            nPlayer->player.setRotation( atan2(-mouse.y+ nPlayer->player.getPosition().y,-mouse.x+ nPlayer->player.getPosition().x) * 180.0f/3.14 + 90);
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ))
            {
                state = END;
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
            {
                nPlayer->changePosition('W');
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
            {
                nPlayer->changePosition('S');
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
            {
                nPlayer->changePosition('A');
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
            {
                nPlayer->changePosition('D');
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
            {
                state = PAUSE;
            }
            if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
            {
                nSetOfBullets->addBullet(nPlayer->player.getPosition().x,nPlayer->player.getPosition().y,nPlayer->player.getRotation(),40);
            }
        }

        nSetOfZombies->changePosition(nPlayer->player.getPosition().x,nPlayer->player.getPosition().y);
        nSetOfBullets->changePosition();
        nSetOfBullets->checkIfOutsideOfMap();
        std::vector< std::pair<int,int> > v1 = colision(nSetOfBullets->onlySprite(),nSetOfZombies->onlySprite());
        std::vector< std::pair<int,int> > v2 = colision(nPlayer->onlySprite(),nSetOfZombies->onlySprite());
        nPlayer->life -= nSetOfZombies->dealDamage(colisionSecondElement(v2));
        nSetOfBullets->deleteCollidingElements(colisionFirstElement(v1));
        nSetOfZombies->deleteCollidingElements(colisionSecondElement(v1));
        changeWaveAndLife();

        nGameWindow->clear();
        nGameWindow->draw(backgroudSprite);
        for(int i=0;i<nSetOfBullets->setOfBullets.size();i++)
            nGameWindow->draw(nSetOfBullets->setOfBullets[i]->bullet);
        for(int i=0;i<nSetOfZombies->setOfZombies.size();i++)
            nGameWindow->draw(nSetOfZombies->setOfZombies[i]->zombie);
        nGameWindow->draw(nPlayer->player);
        nGameWindow->draw(waveText);
        nGameWindow->draw(lifeText);
        nGameWindow->display();

    }
}

void Engine::changeWaveAndLife()
{
    std::string s = waveString + intToString(waveCNT);
    waveText.setString(s);
    s = lifeString + intToString(nPlayer->life);
    lifeText.setString(s);
}
void Engine::backToMenu(std::string s)
{
    sf::Text titleText;
    sf::String titleString = s;
    titleText.setFont(font);
    titleText.setString(titleString);
    titleText.setCharacterSize(100);
    titleText.setPosition(gameWindowWidth/2 - titleText.getGlobalBounds().width/2,50);

    sf::Text backToMenuTableText[2];
    std::string backToMenuTableString[2]= {"MENU","EXIT"};
    for(int i=0;i<2;i++)
    {
        backToMenuTableText[i].setFont(font);
        backToMenuTableText[i].setString(backToMenuTableString[i]);
        backToMenuTableText[i].setCharacterSize(50);
        backToMenuTableText[i].setPosition(gameWindowWidth/2 - backToMenuTableText[i].getGlobalBounds().width/2,200 +i*100);
    }

    bool ifBackToMenu = false;

    while(state != END && state!=END2)
    {
        sf::Event event;
        sf::Vector2f mouse(sf::Mouse::getPosition(*nGameWindow));

        while(nGameWindow->pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ))
            {
                state = END;
            }
            if(backToMenuTableText[0].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                state = END2;
            }
            if(backToMenuTableText[1].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                state = END;
            }
        }

        for(int i=0;i<2;i++)
        {
            if(backToMenuTableText[i].getGlobalBounds().contains(mouse))
                backToMenuTableText[i].setColor(sf::Color::Blue);
            else
                backToMenuTableText[i].setColor(sf::Color::White);
        }

        nGameWindow->clear();
        nGameWindow->draw(titleText);
        for(int i=0;i<2;i++)
            nGameWindow->draw(backToMenuTableText[i]);
        nGameWindow->display();
    }
}


void Engine::pause()
{
    sf::Text titleText;
    std::string titleString = "Pause";
    titleText.setFont(font);
    titleText.setString(titleString);
    titleText.setCharacterSize(100);
    titleText.setPosition(gameWindowWidth/2 - titleText.getGlobalBounds().width/2,50);

    sf::Text pauseTableText[3];
    std::string pauseTableString[3]= {"Unpause", "MENU","EXIT"};

    for(int i=0;i<3;i++)
    {
        pauseTableText[i].setFont(font);
        pauseTableText[i].setString(pauseTableString[i]);
        pauseTableText[i].setCharacterSize(50);
        pauseTableText[i].setPosition(gameWindowWidth/2 - pauseTableText[i].getGlobalBounds().width/2,200 +i*100);
    }
    while(state == PAUSE)
    {
        sf::Event event;
        sf::Vector2f mouse(sf::Mouse::getPosition(*nGameWindow));
        bool ifBackToMenu = false;
        while(nGameWindow->pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ))
            {
                state = END;
            }
            if(pauseTableText[0].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                state = RUN;
            }
            if(pauseTableText[1].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                state = END2;
            }
            if(pauseTableText[2].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {
                state = END;
            }
        }


        for(int i=0;i<3;i++)
        {
            if(pauseTableText[i].getGlobalBounds().contains(mouse))
                pauseTableText[i].setColor(sf::Color::Blue);
            else
                pauseTableText[i].setColor(sf::Color::White);
        }

        nGameWindow->clear();
        nGameWindow->draw(titleText);
        for(int i=0;i<3;i++)
            nGameWindow->draw(pauseTableText[i]);
        nGameWindow->display();
    }

}
