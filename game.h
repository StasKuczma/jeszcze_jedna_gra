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
    //utworzenie obiektow klas uzytych w tej klasie za pomoca pointera
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
    Punkty* punkt1;
    Punkty* punkt2;
    Enemy* enemy1;
    Enemy* enemy2;
    sf::Clock clock;
    sf::Time time_;
    unsigned points;
    int czas;

    //funkcje inicjalizujace wywolywane raz
    void inicjalizujOkno();
    void inicjalizujPlayer();
    void inicjalizujWidok();
    void inicjalizujTlo();
    void inicjalizujPlytki();
    void inicjalizujCzas();
    void inicjalizujPunkty();
    void inicjalizujGUI();
    void inicjalizujEnemy();

    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text time;
    sf::Text koniec;


public:
    //konstruktor
    Game();
    virtual~Game();
    const bool stanOkna() const;//stala ktora mowi o stanie okna
    //funkcje
    void update();
    void render();
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
    //punkty
    void updatePunkty();
    void renderPunkty();
    void zbieraniePunktow();
    //enemy
    void renderEnemy();
    void updateEnemy();
    //czas
    void updateTime();

    void koniecGry();
};

#endif // GAME_H
