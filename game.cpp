#include "game.h"

Game::Game()
{
   this->inicjalizujOkno();
   this->inicjalizujPlayer();
}

Game::~Game()
{
    delete this->player;
}

void Game::inicjalizujOkno()
{
    this->window=new sf::RenderWindow(sf::VideoMode(800, 600), "moja gra");
    this->window->setFramerateLimit(144);
}

const bool Game::stanOkna()const
{
    return this->window->isOpen();
}

void Game::inicjalizujPlayer()
{
    this->player=new Player();
}

void Game::upadatePlayer()
{
    this->player->update();
}
void Game::renderPlayer()
{
    this->player->render(*window);
}

void Game::update()
{
    while (this->window->pollEvent(this->ev))
    {
        if(ev.type==sf::Event::Closed)
        {
            this->window->close();
        }

    }
    this->upadatePlayer();
}

void Game::render()
{
    this->window->clear(sf::Color::White);

    this->renderPlayer();


    this->window->display();

}
