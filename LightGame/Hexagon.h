#ifndef HEXAGON_H
#define HEXAGON_H
#include <SFML/Graphics.hpp>


/**
* Creates the Hexagon that is needed multiple times in order to create a grid.
* An hexagon is caracterized by his positon, his size and his color.
*
**/
class Hexagon
{
private:
    sf::CircleShape _hexa;
    float _size;
    sf::Color _color;

public:
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --Hexagon constructor--
     *
     * Sets the parameters for a hexagon.
     * float size: CircleShape Radius
     * sf::Color color: sets the hexagon's color
     * No return type.
     */
    Hexagon(float size, sf::Color color);


    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --DrawHex--
     *
     * Draws a hexagon on the specified window
     * sf::RenderWindow: Window on which the game
     * is rendered and played.
     *
     * No return type.
     */

    void DrawHex(sf::RenderWindow &w);

    sf::Vector2f getPosition();

    void setPosition(sf::Vector2f pos);

    sf::CircleShape getHex() const;

    sf::Color getColor();

    void setColor(sf::Color c);
};

#endif // HEXAGON_H
