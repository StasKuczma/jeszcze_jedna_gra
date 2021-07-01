#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>


class Enemy
{
private:
    sf::Sprite sprite;
    sf::Texture tekstura;
    sf::RectangleShape ksztalt;
    std::vector<sf::RectangleShape> points;
    int polozenieX;
    int polozenieY;

    void inicjalizujEnemy();
    void inicjakizujtekture();
public:
    Enemy(int x);
    const sf::FloatRect getGlobalBounds() const;
    const sf::Vector2f getPosition() const;
    void render(sf::RenderTarget &target);
    void goombaRuch();
    int kierunekRuchu();


};

#endif // ENEMY_H
