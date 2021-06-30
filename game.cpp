#include "game.h"
#include <vector>

Game::Game()
{
   this->inicjalizujOkno();
   this->inicjalizujPlayer();
   this->inicjalizujWidok();
   this->inicjalizujTlo();
   this->inicjalizujPlytki();
   this->imicjalizujMape();
   this->inicjalizujPunkty();
}

Game::~Game()
{
    delete this->player;
}

void Game::inicjalizujPlayer()
{
    this->player=new Player();
}
void Game::inicjalizujPlytki()
{
    this->plytka=new Plytka(100.f,650.f);
    this->plytka2=new Plytka(200.f,550.f);
    this->plytka3=new Plytka(300.f,450.f);
    //this->plytka2->ustaw(100.f,620.f);
}
void Game::inicjalizujPunkty()
{
    this->punkt1=new Punkty(150,650);
}
void Game::imicjalizujMape()
{
    //this->MapaPlytek=new class MapaPlytek();
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

//const sf::FloatRect Player::getGlobalBounds() const
//{
//    return this->sprite.getGlobalBounds();
//}

void Game::kolizja()
{

}
void Game::wymiary()
{

}
void Game::updateKolizjizOknem()
{
    if(this->player->getGlobalBounds().left < 0.f)//ograniczenie mapy z lewej
        {

            this->player->resetujPredkosc();
            this->player->ustawPozycje(0.f, this->player->getGlobalBounds().top);
        }
    if(this->player->getGlobalBounds().left > 2120.f)//ograniczenie mapy z prawej
        {

            this->player->resetujPredkosc();
            this->player->ustawPozycje(2120.f, this->player->getGlobalBounds().top);
        }
    if(this->player->getGlobalBounds().top+this->player->getGlobalBounds().height//ograniczenie z dolu
            >(this->window->getSize().y-100))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(
            this->player->getGlobalBounds().left ,
            this->window->getSize().y-this->player->getGlobalBounds().height-100);
    }
    if(this->player->getGlobalBounds().top+this->player->getGlobalBounds().height//ograniczenie z gory
            <(this->window->getSize().y-750))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(
            this->player->getGlobalBounds().left ,
            this->window->getSize().y-this->player->getGlobalBounds().height-750);
    }

}

void Game::updateKolizji()
{

    if(this->player->getGlobalBounds().contains(this->plytka->getPosition().x+20,this->plytka->getPosition().y))
    {
        std::cout<<"tu jestem"<<std::endl;
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka->getGlobalBounds().top-this->plytka->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka2->getPosition().x+20,this->plytka2->getPosition().y))
    {
        std::cout<<"jestem"<<std::endl;
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka2->getGlobalBounds().top-this->plytka2->getGlobalBounds().height);
    }

    if(this->player->getGlobalBounds().contains(this->plytka3->getPosition().x+20,this->plytka3->getPosition().y))
    {
        std::cout<<"tu jestem"<<std::endl;
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka3->getGlobalBounds().top-this->plytka3->getGlobalBounds().height);
    }


}

void Game::updateOkna()
{
    sf::Vector2f temp;
    temp.x=this->player->getGlobalBounds().left;
    temp.y=this->player->getGlobalBounds().top;

    if(this->player->getGlobalBounds().left < 270.f)
    {
        //std::cout<<this->player->getGlobalBounds().left<<std::endl;
        this->widok.setCenter(270.f,temp.y-50);
    }
    else if(this->player->getGlobalBounds().left > 1890.f)
    {
        //std::cout<<this->player->getGlobalBounds().left<<std::endl;
        this->widok.setCenter(1890.f,temp.y-50);
    }
    else
    {
        this->widok.setCenter(temp.x,temp.y-50);
    }
}

void Game::upadatePlayer()
{
    this->player->update();

}

void Game::renderPlayer()
{
    this->player->render(*window);
}

void Game::updatePlytka()
{
    //this->plytka2->move(-2,0);//czyli tak to dzila xD
    //this->plytka->move(1,0);

}

void Game::renderPlytka()
{
    this->plytka->render(*window);
    this->plytka2->render(*window);
    this->plytka3->render(*window);

}
void Game::renderPunkty()
{
    this->punkt1->render(*window);
}

void Game::updateMapa()
{
    this->MapaPlytek->ruszaj();
}
void Game::renderMapa()
{
    this->MapaPlytek->render(*window);
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
    this->updatePlytka();
    this->updateMapa();
    this->updateOkna();
    this->updateKolizji();
    this->updateKolizjizOknem();
    //std::cout<<this->player->getGlobalBounds().left<<"    "<<this->player->getGlobalBounds().top<<std::endl;
}

void Game::render()
{
    this->window->clear(sf::Color::White);
    this->window->draw(tloSprite);

    this->renderPlayer();
    this->renderPlytka();
    this->renderPunkty();

    //this->renderMapa();
    this->window->display();

}
