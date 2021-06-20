#include "player.h"

Player::Player()
{
    this->inicjakizujtektura();
    this->inicjalizujsprite();
}
Player::~Player()
{

}

void Player::inicjalizujsprite()
{
    this->sprite.setTexture(this->tekstura);
}
void Player::inicjakizujtektura()
{

    if(!this->tekstura.loadFromFile("D:/Qt-sfml/projekt_gra_ten_jedyny/build-game-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/tekstury/guy.png"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla garacza"<<std::endl;
    }

}



void Player::update()
{
    this->updateRuch();
}

void Player::render(sf::RenderTarget & target)
{
    target.draw(this->sprite);
}

void Player::updateRuch()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//lewo
    {
        this->sprite.move(-1.f,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//prawo
    {
        this->sprite.move(1.f,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//gora
    {
        this->sprite.move(0.f,-1.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))//dol
    {
        this->sprite.move(0.f,1.f);
    }
}

