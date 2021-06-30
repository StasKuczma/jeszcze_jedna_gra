#ifndef MAPAPLYTEK_H
#define MAPAPLYTEK_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "plytka.h"


class MapaPlytek:public Plytka
{
private:
    Plytka* Plytka1;

    sf::RectangleShape* box;
    std::vector<sf::RectangleShape> boxes;

public:
    MapaPlytek(int x, int y);

    void inicjalizujMape();
    void ruszaj();

};

#endif // MAPAPLYTEK_H
