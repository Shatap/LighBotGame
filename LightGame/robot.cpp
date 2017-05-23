#include "robot.h"

Robot::Robot()
{
    _robot.setFillColor(sf::Color::Yellow);
    _robot.setPointCount(3);
    _robot.setOutlineColor(sf::Color::Green);
    _robot.setOutlineThickness(4);
    _robot.setPosition(120, 145);
    _robot.setRadius(12);
//    _robot.setOrigin();
}

void Robot::draw_bot(sf::RenderWindow &w)
{
    w.draw(_robot);
}
