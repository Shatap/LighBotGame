#include "robot.h"

Robot::Robot()
{
    _robot.setFillColor(sf::Color::Red);
    _robot.setPosition(120, 145);
    _robot.setSize({10,10});
//    _robot.setOrigin();
}

void Robot::draw_bot(sf::RenderWindow &w)
{
    w.draw(_robot);
}
