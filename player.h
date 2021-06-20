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

    //animacja

    //ruch

    void inicjalizujsprite();
    void inicjakizujtektura();

public:
    Player();
    virtual ~Player();

    //funkcje
    void update();
    void render(sf::RenderTarget &target);
    void updateRuch();
};

#endif // PLAYER_H
