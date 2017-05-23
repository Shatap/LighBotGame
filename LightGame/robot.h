#ifndef ROBOT_H
#define ROBOT_H
#include "Application.h"
#include "robot.h"
#include <SFML/Graphics.hpp>


class Robot
{
private:
    sf::CircleShape _robot;
public:
    Robot();
    void draw_bot(sf::RenderWindow &w);
    bool isMoving();
    int getAngle();
    int getAltitude();
};

#endif // ROBOT_H
