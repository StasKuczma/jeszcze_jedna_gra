#ifndef PUNKTY_H
#define PUNKTY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class Punkty
{
private:
    sf::Sprite sprite;
    sf::Texture tekstura;
    sf::RectangleShape ksztalt;
    std::vector<sf::RectangleShape> points;
    int polozenieX;
    int polozenieY;

    void inicjalizujPunkty();
    void inicjakizujtekture();
public:
    Punkty(int x,int y);
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosition() const;
    void render(sf::RenderTarget &target);
    void updatePunkty1();
    void polozenie();

};

#endif // PUNKTY_H
