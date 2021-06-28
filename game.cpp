#include "game.h"

Game::Game()
{
   this->inicjalizujOkno();
   this->inicjalizujPlayer();
   this->inicjalizujWidok();
   this->inicjalizujTlo();
}

Game::~Game()
{
    delete this->player;
}

void Game::inicjalizujOkno()
{
    this->window=new sf::RenderWindow(sf::VideoMode(1080, 800), "moja gra");
    this->window->setFramerateLimit(60);
}
void Game::inicjalizujWidok()
{
    this->widok= *new sf::View (sf::Vector2f(0.f,0.f) ,sf::Vector2f(540.f,400.f));
    //this->window->setView(widok);
    this->widok.setSize(540.f,400.f);
}
void Game::inicjalizujTlo()
{
    if(!this->tlo.loadFromFile("tekstury/tlo2.png"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla garacza"<<std::endl;
    }

    tlo.loadFromFile("tekstury/tlo2.png");

    this->tloSprite.setTexture(this->tlo);

}

const bool Game::stanOkna()const
{
    return this->window->isOpen();
}

const sf::FloatRect Player::getGlobalBounds() const
{
    return this->sprite.getGlobalBounds();
}

void Game::updateKolizji()
{
    if(this->player->getGlobalBounds().top+this->player->getGlobalBounds().height
            >(this->window->getSize().y-100))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(
            this->player->getGlobalBounds().left ,
            this->window->getSize().y-this->player->getGlobalBounds().height-100);
    }
//    if(this->player->getGlobalBounds().top+this->player->getGlobalBounds().height==600)
//    {

//    }
}
void Game::inicjalizujPlayer()
{
    this->player=new Player();
}

void Game::updateOkna()
{
    sf::Vector2f temp;
    temp.x=this->player->getGlobalBounds().left;
    temp.y=this->player->getGlobalBounds().top;
    this->widok.setCenter(temp.x,temp.y-50);
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
    this->window->setView(widok);
    this->upadatePlayer();
    this->updateOkna();
    this->updateKolizji();
}

void Game::render()
{
    this->window->clear(sf::Color::White);
    this->window->draw(tloSprite);
    this->renderPlayer();


    this->window->display();

}
