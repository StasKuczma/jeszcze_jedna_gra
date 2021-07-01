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



int main()
{
    srand(static_cast<unsigned>(time(0)));

    Game game;

    while(game.stanOkna())
    {
        game.update();
        game.render();
    }
    return 0;
}
