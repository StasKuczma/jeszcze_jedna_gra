#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "player.h"

class Game
{
private:
    sf::RenderWindow* window;
    sf::Event ev;

    Player* player;

    void inicjalizujOkno();
    void inicjalizujPlayer();

public:
    //konstruktory
    Game();
    virtual~Game();
    //funkcje
    const bool stanOkna() const;//stała która mówi o stanie okna

    void update();
    void render();
    //update gracza
    void upadatePlayer();
    void renderPlayer();
};

#endif // GAME_H
