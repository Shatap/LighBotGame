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
public:
    Robot();
    void draw_bot(sf::RenderWindow &w);
    void bot_in_hex();
    bool isMoving();
    int getAngle();
    int getAltitude();
    void setPosition();
    void setRotationRight();
    void setRotationLeft();
    sf::CircleShape getRobot();
    void setPosManually(sf::Vector2f);



    sf::Vector2f getPosition();
};

#endif // ROBOT_H
