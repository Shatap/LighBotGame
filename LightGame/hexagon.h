#ifndef HEXAGON_H
#define HEXAGON_H
#include <SFML/Graphics.hpp>



class Hexagon
{
private:
    sf::CircleShape _hexa;
    float _size;
    sf::Color _color;

public:
    Hexagon();
    Hexagon(float size, sf::Color color);
    ~Hexagon();
    void DrawHex(sf::RenderWindow &w);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
};

#endif // HEXAGON_Hnau
