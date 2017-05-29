#include "hexagon.h"



Hexagon::Hexagon(float size, sf::Color color)
    :_size{size},_color{color}

{

    _hexa.setPointCount(6);
    _hexa.setRadius(size);
    _hexa.setFillColor(color);
    _hexa.setOutlineThickness(2);
    _hexa.setRotation(30);
    _hexa.setOrigin(30,30);


}

Hexagon::~Hexagon()
{

}

void Hexagon::DrawHex(sf::RenderWindow &w)
{
    w.draw(_hexa);
}

sf::Vector2f Hexagon::getPosition()
{
    return _hexa.getPosition();
}

void Hexagon::setPosition(sf::Vector2f pos)
{
    _hexa.setPosition(pos);
}

sf::CircleShape Hexagon::getHex() const
{
return this->_hexa;

}

sf::Color Hexagon::getColor()
{
    return this->_color;
}

void Hexagon::setColor(sf::Color c)
{
    _hexa.setFillColor(c);
}

