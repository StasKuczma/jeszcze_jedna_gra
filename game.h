#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "player.h"
#include "plytka.h"
#include "mapaplytek.h"
#include "punkty.h"

class Game
{
private:
    sf::RenderWindow* window;
    sf::View widok;
    sf::Event ev;
    sf::Texture tlo;
    sf::Sprite tloSprite;

    Player* player;
    Plytka* plytka;
    Plytka* plytka2;
    Plytka* plytka3;
    MapaPlytek* MapaPlytek;
    std::vector<sf::RectangleShape> punkty;
    Punkty* punkt1;

    void inicjalizujOkno();
    void inicjalizujPlayer();
    void inicjalizujWidok();
    void inicjalizujTlo();
    void inicjalizujPlytki();
    void imicjalizujMape();
    void inicjalizujPunkty();

public:
    //konstruktory
    Game();
    virtual~Game();
    //funkcje
    const bool stanOkna() const;//stała która mówi o stanie okna

    void update();
    void render();
    void kolizja();
    //update gracza
    void upadatePlayer();
    void renderPlayer();
    void updateKolizji();
    void updateKolizjizOknem();
    void updateOkna();
    void wymiary();

    //platformy
    void renderPlytka();
    void updatePlytka();

    //mapa
    void renderMapa();
    void updateMapa();
    //punkty
    void updatePunkty();
    void renderPunkty();
};

#endif // GAME_H
