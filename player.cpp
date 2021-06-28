#include "player.h"
#include <cmath>

Player::Player()
{
    this->inicjakizujtektura();
    this->inicjalizujsprite();
    this->inicjlizujFizyke();
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

    if(!this->tekstura.loadFromFile("tekstury/guy.png"))
    {
      std::cout<<"nie mozna byl wczytac pliku dla garacza"<<std::endl;
    }

}
void Player::inicjlizujFizyke()
{
    this->maxPrekosc=10.f;
    this->minPrekosc=1.f;
    this->przyspieszenie=3.f;
    this->zwolnienie=0.9f;
    this->grawitacja=2.f;
    this->maxPredkoscY=24.f;
}

void Player::updateFizyka()
{
    this->predkosc.y+=1.0f*this->grawitacja;

    if(std::abs(this->predkosc.y)>this->maxPredkoscY)
    {
        this->predkosc.y=this->maxPredkoscY*((this->predkosc.y< 0.f )? -1.f:1.f);
    }
    //zwolnieie

    this->predkosc.x*=this->zwolnienie;

    //ograniczenie
    if(std::abs(this->predkosc.x)<this->minPrekosc)
        {this->predkosc.x=0.f;}
    if(std::abs(this->predkosc.y)<this->minPrekosc)
        {this->predkosc.y=0.f;}

    //std::cout<<std::abs(this->predkosc.x)<<std::endl;
    this->sprite.move(this->predkosc.x,0.f);
    this->sprite.move(0.f,this->predkosc.y);

}
void Player::ruch(float dir_x,float dir_y)
{
    //przyspieszenie
        this->predkosc.x+=dir_x*this->przyspieszenie;
        this->predkosc.y+=dir_y*this->przyspieszenie;
    //ograniczenie
      if((std::abs(this->predkosc.x))>this->maxPrekosc)
      {
          if(this->predkosc.x>0)
          {
              this->predkosc.x=maxPrekosc;
          }
          else if(this->predkosc.x<0)
          {
              this->predkosc.x=-1.f*maxPrekosc;
          }
      }
      if((std::abs(this->predkosc.y))>this->maxPrekosc)
      {
          if(this->predkosc.y>0)
          {
              this->predkosc.y=maxPredkoscY;
          }
          else if(this->predkosc.y<0)
          {
              this->predkosc.y=-1.f*maxPredkoscY;
          }
      }

}

void Player::resetujPredkosc()
{
   this->predkosc.y=0.f;
}
void Player::ustawPozycje(float x,float y)
{
    this->sprite.setPosition(x,y);
}

void Player::skok()
{
    this->moze_skakac=1;
    this->licznik_spacji=0;
}

void Player::update()
{
    this->updateRuch();
    this->updateFizyka();
}

void Player::render(sf::RenderTarget & target)
{
    target.draw(this->sprite);
}

void Player::updateRuch()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//lewo
    {
        this->ruch(-1.f,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//prawo
    {
        this->ruch(1.f,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))//skok
    {
            if(moze_skakac)
            {
            std::cout<<"skok"<<std::endl;
            this->ruch(0.f,-10.f);
            moze_skakac=0;
            }
    }


//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//gora
//    {
//        this->sprite.move(0.f,-1.f);
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))//dol
//    {
//        this->sprite.move(0.f,1.f);
//    }
}

