#ifndef ROBOT_H
#define ROBOT_H
#include "Application.h"
#include "robot.h"
#include "hexagon.h"
#include "grid.h"
#include <SFML/Graphics.hpp>


class Robot
{
private:
    sf::CircleShape _robot;
    Hexagon *_currenthex;
    int _rate;
    float const PI = 3.1415926;
    sf::Texture _downTexture;
    sf::Texture _sideTexture;
    bool _textureChange;
public:
    Robot();
    void draw_bot(sf::RenderWindow &w);
    bool bot_in_hex(Grid &g);
    bool isMoving();
    void lightHex(Grid &g, sf::RenderWindow &w);
    int getAngle();
    int getAltitude();
    void setPosition(Grid &g);
    void setRotationRight();
    void setRotationLeft();
    sf::CircleShape getRobot();
    void setPosManually(sf::Vector2f);
    void setTexture(sf::Texture &t);



    sf::Vector2f getPosition();
};

#endif // ROBOT_H
