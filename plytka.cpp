#include "plytka.h"

Plytka::Plytka(int x,int y)
{
    this->inicjakizujtekture();
    this->inicjalizujPlytke();
    this->sprite.setPosition(x,y);

}


void Plytka::inicjalizujPlytke()
{

    this->sprite.setTexture(this->tekstura);
    //this->sprite.setPosition(600,650);
    this->sprite.setScale(0.6,0.6);

}

void Plytka::inicjakizujtekture()
{

    if(!this->tekstura.loadFromFile("tekstury/box2.jpg"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla boxu"<<std::endl;
    }

}

void Plytka::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

const sf::Vector2f Plytka::getPosition()const
{
    return this->sprite.getPosition();

}

const sf::FloatRect Plytka::getGlobalBounds()const
{
    return this->sprite.getGlobalBounds();
}

const sf::RectangleShape Plytka::getShape()const
{
    return this->ksztalt;
}

void Plytka::move(int x,int y)
{
    this->sprite.move(x,y);
}
void Plytka::ustaw(int x, int y)
{
    this->sprite.setPosition(x,y);
}
