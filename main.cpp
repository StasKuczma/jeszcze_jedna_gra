//sfml
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
//system
#include <iostream>
#include <time.h>
#include <ctime>
#include "game.h"

using namespace std;

int main()
{

    srand(static_cast<unsigned>(time(0)));

    Game game;

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOrigin(60.0,30.0);

    while(game.stanOkna())
    {
        game.update();
        game.render();
    }
    return 0;
}
