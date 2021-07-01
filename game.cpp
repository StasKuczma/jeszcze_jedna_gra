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
   this->inicjalizujGUI();
   this->inicjalizujEnemy();
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
    this->plytka=new Plytka(100.f,600.f);
    this->plytka2=new Plytka(250.f,550.f);
    this->plytka3=new Plytka(400.f,450.f);
    this->plytka4=new Plytka(630.f,400.f);
    this->plytka5=new Plytka(750.f,550.f);
    this->plytka6=new Plytka(900.f,450.f);
    this->plytka7=new Plytka(1100.f,600.f);
    this->plytka8=new Plytka(1350.f,550.f);
    this->plytka9=new Plytka(1500.f,450.f);
    //this->plytka2->ustaw(100.f,620.f);
}
void Game::inicjalizujPunkty()
{

    this->punkt1=new Punkty(350,650);
    this->punkt2=new Punkty(350,650);
    this->points=0;

    //this->punkty.emplace_back(punkt1);

}
void Game::imicjalizujMape()
{
    //this->MapaPlytek=new class MapaPlytek();
}


void Game::inicjalizujGUI()
{
    if(!this->font.loadFromFile("font/Dunkin.otf"))
    {
         std::cout<<"blad czcionki"<<std::endl;
    }
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(50);
    this->pointText.setFillColor(sf::Color::White);
    //this->pointText.setString("test");

    //this->pointText.move(100,500);
}

void Game::inicjalizujEnemy()
{
    this->enemy1= new Enemy(100);
    this->enemy2= new Enemy(1800);
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
    if(!this->tlo.loadFromFile("tekstury/skrr.png"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla garacza"<<std::endl;
    }

    tlo.loadFromFile("tekstury/skrr.png");

    this->tloSprite.setTexture(this->tlo);
}



const bool Game::stanOkna()const
{
    return this->window->isOpen();
}

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

void Game::updateKilizjizGoomba()
{
    if(this->player->getGlobalBounds().contains(this->enemy1->getPosition()))
    {

        this->points=0;
    }
    if(this->player->getGlobalBounds().contains(this->enemy2->getPosition()))
    {

        this->points=0;
    }



}

void Game::updateKolizji()
{

    if(this->player->getGlobalBounds().contains(this->plytka->getPosition().x+20,this->plytka->getPosition().y))
    {
        std::cout<<"elo"<<std::endl;
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka->getGlobalBounds().top-this->plytka->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka2->getPosition().x+20,this->plytka2->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka2->getGlobalBounds().top-this->plytka2->getGlobalBounds().height);
    }

    if(this->player->getGlobalBounds().contains(this->plytka3->getPosition().x+20,this->plytka3->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka3->getGlobalBounds().top-this->plytka3->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka4->getPosition().x+20,this->plytka4->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka4->getGlobalBounds().top-this->plytka4->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka5->getPosition().x+20,this->plytka5->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka5->getGlobalBounds().top-this->plytka5->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka6->getPosition().x+20,this->plytka6->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka6->getGlobalBounds().top-this->plytka6->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka7->getPosition().x+20,this->plytka7->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka7->getGlobalBounds().top-this->plytka7->getGlobalBounds().height);
    }

    if(this->player->getGlobalBounds().contains(this->plytka8->getPosition().x+20,this->plytka8->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka8->getGlobalBounds().top-this->plytka8->getGlobalBounds().height);
    }
    if(this->player->getGlobalBounds().contains(this->plytka9->getPosition().x+20,this->plytka9->getPosition().y))
    {
        this->player->resetujPredkosc();
        this->player->skok();
        this->player->ustawPozycje(this->player->getGlobalBounds().left,this->plytka9->getGlobalBounds().top-this->plytka9->getGlobalBounds().height);
    }


}

void Game::updateOkna()
{
    sf::Vector2f temp;
    temp.x=this->player->getGlobalBounds().left;
    temp.y=this->player->getGlobalBounds().top;

    if(this->player->getGlobalBounds().left < 270.f)
    {
        this->widok.setCenter(270.f,temp.y-50);
    }
    else if(this->player->getGlobalBounds().left > 1890.f)
    {
        this->widok.setCenter(1890.f,temp.y-50);
    }
    else
    {
        this->widok.setCenter(temp.x,temp.y-50);
    }
}
void Game::updatePunkty()
{
    //this->punkt1->updatePunkty1();
}

void Game::upadatePlayer()
{
    this->player->update();
}

void Game::updateEnemy()
{
    this->enemy1->goombaRuch();
    this->enemy1->kierunekRuchu();
    this->enemy2->goombaRuch();
    this->enemy2->kierunekRuchu();

    if(this->enemy1->getGlobalBounds().contains(2100.f,650.f))
    {
        this->enemy1->kierunekRuchu();
        //std::cout<<this->enemy1->getGlobalBounds().left<<std::endl;
    }
    else if (this->enemy1->getGlobalBounds().contains(0.f,650.f))
    {
        this->enemy1->kierunekRuchu();
    }

    if(this->enemy2->getGlobalBounds().contains(2100.f,650.f))
    {
        this->enemy2->kierunekRuchu();
        //std::cout<<this->enemy1->getGlobalBounds().left<<std::endl;
    }
    else if (this->enemy2->getGlobalBounds().contains(0.f,650.f))
    {
        this->enemy2->kierunekRuchu();
    }

}
void Game::updateGUI()
{
    std::stringstream ss;
    ss<<this->points;
    this->pointText.setPosition(widok.getCenter().x-250.f,widok.getCenter().y-200.f);
    this->pointText.setString(ss.str());

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

void Game::zbieraniePunktow()
{
    if((this->player->getGlobalBounds().contains(
                this->punkt1->getPosition().x+20,this->punkt1->getPosition().y)))
    {
        //std::cout<<"punkt zebrany"<<std::endl;
        //this->player->plus_jeden();//dodanie punktu
        this->punkt1->polozenie();//losowa zmiana polozenia punktu
        this->points++;

    }
    if(this->player->getGlobalBounds().contains(
                                    this->punkt2->getPosition().x+20,this->punkt2->getPosition().y))
    {
        this->punkt2->polozenie();//losowa zmiana polozenia punktu
        this->points++;
    }
}

void Game::renderPlytka()
{
    this->plytka->render(*window);
    this->plytka2->render(*window);
    this->plytka3->render(*window);
    this->plytka4->render(*window);
    this->plytka5->render(*window);
    this->plytka6->render(*window);
    this->plytka7->render(*window);
    this->plytka8->render(*window);
    this->plytka9->render(*window);

}
void Game::renderPunkty()
{
    this->punkt1->render(*window);
    this->punkt2->render(*window);
}

void Game::renderGUI()
{
    this->window->draw(this->pointText);
}
void Game::renderEnemy()
{
    this->enemy1->render(*window);
    this->enemy2->render(*window);
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
    this->updateGUI();
    this->upadatePlayer();
    this->updatePlytka();
    this->updateMapa();
    this->updateOkna();
    this->updateKolizji();
    this->updateKolizjizOknem();
    this->updatePunkty();
    this->updateEnemy();
    this->updateKilizjizGoomba();

    this->zbieraniePunktow();
    //std::cout<<this->player->getGlobalBounds().left<<"    "<<this->player->getGlobalBounds().top<<std::endl;
}

void Game::render()
{
    this->window->clear(sf::Color::White);
    this->window->draw(tloSprite);

    this->renderPlayer();
    this->renderPlytka();
    this->renderPunkty();
    this->renderGUI();
    this->renderEnemy();


    //this->renderMapa();
    this->window->display();

}
