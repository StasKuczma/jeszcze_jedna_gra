#ifndef PLYTKA_H
#define PLYTKA_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>


class Plytka
{
private:
    sf::Sprite sprite;
    sf::Texture tekstura;
    sf::RectangleShape ksztalt;

    void inicjalizujPlytke();
    void inicjakizujtekture();
public:
    Plytka(int x,int y);
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosition() const;

    void render(sf::RenderTarget &target);
    const sf::RectangleShape getShape()const;
    void move(int x,int y);
    void ustaw(int x, int y);

};

#endif // PLYTKA_H
