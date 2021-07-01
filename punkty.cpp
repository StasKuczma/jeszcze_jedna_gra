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
    this->sprite.setScale(0.35,0.35);
    polozenieX=0;
    polozenieY=0;

}

void Punkty::inicjakizujtekture()
{

    if(!this->tekstura.loadFromFile("tekstury/Punkt1.jpg"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla Punktu"<<std::endl;
    }

}

void Punkty::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

void Punkty::polozenie()
{
    this->polozenieX=((rand()%1500)+20);
    this->polozenieY=((rand()%300)+400);
    this->sprite.setPosition(polozenieX,polozenieY);
}

void Punkty::updatePunkty1()
{
    this->polozenie();
}
const sf::Vector2f Punkty::getPosition()const
{
    return this->sprite.getPosition();

}

const sf::FloatRect Punkty::getGlobalBounds()const
{
    return this->sprite.getGlobalBounds();
}

