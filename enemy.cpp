#include "enemy.h"

Enemy::Enemy(int x)
{
    this->inicjakizujtekture();
    this->inicjalizujEnemy();
    this->polozenieX=-4.f;
    this->sprite.setPosition(x,650);
}

int Enemy::kierunekRuchu()
{
    this->polozenieX=polozenieX*(-1.f);
    return polozenieX;
}

void Enemy::inicjalizujEnemy()
{

    this->sprite.setTexture(this->tekstura);
    //this->sprite.setPosition(600,650);
    this->sprite.setScale(0.1,0.1);
    //this->sprite.setPosition(1000.f,650.f);

}

void Enemy::inicjakizujtekture()
{

    if(!this->tekstura.loadFromFile("tekstury/goomba.PNG"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla goomba"<<std::endl;
    }

}

const sf::Vector2f Enemy::getPosition()const
{
    return this->sprite.getPosition();

}

const sf::FloatRect Enemy::getGlobalBounds()const
{
    return this->sprite.getGlobalBounds();
}

void Enemy::goombaRuch()
{
    this->sprite.move(this->kierunekRuchu(),0);
}

void Enemy::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}
