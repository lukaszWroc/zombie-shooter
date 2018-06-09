#include "Game.h"

Game::Game()
{
    gameWindow.create(sf::VideoMode(gameWindowWidth,gameWindowHeight),"zombie shooter");
    state=MENU;
    if(!font.loadFromFile("data\\arial.ttf"))
       throw std::invalid_argument("can't load arial.ttf");

    std::string title_string="zombie shooter";
    title.setString(title_string);
    title.setFont(font);
    title.setCharacterSize(80);

    std::string menuOptionsTableString[2] = {"PLAY", "EXIT"};
    title.setPosition(gameWindowWidth/2 - title.getGlobalBounds().width/2,20);

    for(int i=0;i<2;i++)
    {
        menuOptionsTableText[i].setString(menuOptionsTableString[i]);
        menuOptionsTableText[i].setCharacterSize(50);
        menuOptionsTableText[i].setFont(font);
        menuOptionsTableText[i].setPosition(gameWindowWidth/2 - menuOptionsTableText[i].getGlobalBounds().width/2,200 +i*100);
    }
}


void Game::runGame()
{
    while(state!=END)
    {
        switch(state)
        {
            case MENU:
                displayMenu();
                break;
            case GAME:
                displayGame();
                break;
        }
    }
}

void Game::displayMenu()
{
    while(state==MENU)
    {
        sf::Event event;
        sf::Vector2f mouse(sf::Mouse::getPosition(gameWindow));
        while(gameWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                state = END;
            if(menuOptionsTableText[1].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
                state = END;
            if(menuOptionsTableText[0].getGlobalBounds().contains(mouse) &&event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
                state = GAME;
        }
        for(int i=0;i<2;i++)
        {
            if(menuOptionsTableText[i].getGlobalBounds().contains(mouse))
                menuOptionsTableText[i].setColor(sf::Color::Blue);
            else
                menuOptionsTableText[i].setColor(sf::Color::White);
        }
        gameWindow.clear();
        gameWindow.draw(title);
        for(int i=0;i<2;i++)
            gameWindow.draw(menuOptionsTableText[i]);
        gameWindow.display();
    }
}

void Game::displayGame()
{
    Engine *engine = new Engine(gameWindow);
    if(engine->runEngine())
        state = MENU;
    else
        state = END;
    delete engine;
}
