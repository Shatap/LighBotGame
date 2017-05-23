#include "robot.h"

Robot::Robot()
{
    _robot.setFillColor(sf::Color::Yellow);
    _robot.setPointCount(3);
    _robot.setOutlineColor(sf::Color::Green);
    _robot.setOutlineThickness(4);
    _robot.setPosition(120, 145);
    _robot.setRadius(8);


}

void Robot::draw_bot(sf::RenderWindow &w)
{
    w.draw(_robot);
}

void Robot::bot_in_hex()
{

}

void Robot::setPosition(const Hexagon & hex)
{
    _robot.setPosition({hex.getHex().getPosition().x-5,hex.getHex().getPosition().y+5});
}

void Robot::setRotationRight()
{
    this->_robot.setRotation(45);
}
void Robot::setRotationLeft()
{
    this->_robot.setRotation(-45);
}


sf::Vector2f Robot::getPosition()
{
    return this->_robot.getPosition();
}


