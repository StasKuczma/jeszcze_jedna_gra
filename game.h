#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "player.h"
#include "plytka.h"
#include "mapaplytek.h"
#include "punkty.h"
#include "enemy.h"

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
    Plytka* plytka4;
    Plytka* plytka5;
    Plytka* plytka6;
    Plytka* plytka7;
    Plytka* plytka8;
    Plytka* plytka9;
    MapaPlytek* MapaPlytek;
    std::vector<sf::RectangleShape> punkty;
    Punkty* punkt1;
    Punkty* punkt2;
    Enemy* enemy1;
    Enemy* enemy2;
    unsigned points;

    void inicjalizujOkno();
    void inicjalizujPlayer();
    void inicjalizujWidok();
    void inicjalizujTlo();
    void inicjalizujPlytki();
    void imicjalizujMape();
    void inicjalizujPunkty();
    void inicjalizujGUI();
    void inicjalizujEnemy();

    //GUI
    sf::Font font;
    sf::Text pointText;


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
    void updateKilizjizGoomba();
    void updateOkna();
    void updateGUI();
    void renderGUI();
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
    void zbieraniePunktow();
    //enemy
    void renderEnemy();
    void updateEnemy();
};

#endif // GAME_H
