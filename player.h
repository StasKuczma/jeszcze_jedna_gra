#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture tekstura;
    sf::RectangleShape ksztalt;

    //animacja
    //fizyka
    sf::Vector2f predkosc;
    float przyspieszenie;
    float zwolnienie;
    float maxPrekosc;
    float minPrekosc;
    float grawitacja;
    float maxPredkoscY;
    bool moze_skakac;
    int licznik_spacji;
    int licznik_punktow;

    //ruch
    void inicjalizujsprite();
    void inicjakizujtektura();//tutaj jest literowka
    void inicjalizujzmienne();
    void inicjlizujFizyke();

public:
    Player();
    virtual ~Player();

    const sf::FloatRect getGlobalBounds()const;
    const sf::Vector2f getPosition()const;


    void resetujPredkosc();
    void ustawPozycje(const float x,const float y);
    const sf::RectangleShape getShape()const;

    //funkcje
    void update();
    void render(sf::RenderTarget &target);
    void updateRuch();
    void updateFizyka();
    void ruch(float dir_x,float dir_y);
    void skok();
    void wymiary();
    void plus_jeden();
};

#endif // PLAYER_H
