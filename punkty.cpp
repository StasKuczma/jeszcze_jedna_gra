#include "punkty.h"

Punkty::Punkty(int x, int y)
{
    this->inicjakizujtekture();
    this->inicjalizujPunkty();
    this->sprite.setPosition(x,y);

}


void Punkty::inicjalizujPunkty()
{

    this->sprite.setTexture(this->tekstura);
    //this->sprite.setPosition(600,650);
    this->sprite.setScale(0.6,0.6);

}

void Punkty::inicjakizujtekture()
{

    if(!this->tekstura.loadFromFile("tekstury/box.jpg"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla boxu"<<std::endl;
    }

}

void Punkty::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

