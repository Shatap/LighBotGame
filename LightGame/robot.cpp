#include "robot.h"

Robot::Robot():_rate{0}
{
    //_robot.setOutlineColor(sf::Color::Green);
    //_robot.setOutlineThickness(4);
    _robot.setRadius(20);
    _robot.setPosition({60,80});
    _robot.setOrigin({20,20});
    _robot.rotate(30);


}

void Robot::draw_bot(sf::RenderWindow &w)
{
    sf::Texture texture;
    texture.loadFromFile("/home/Oka/LighBotGame/LightGame/Sources/arrow.jpg");
    _robot.setTexture(&texture);
    w.draw(_robot);
}

void Robot::bot_in_hex()
{

}

void Robot::setPosition()
{
    if(_rate == 0)
    {
        _robot.setPosition({getPosition().x+(32*cos(3.14/3)),getPosition().y+(32*sin((3.14)/3))});
    }

    else if(_rate == 1)
    {
        _robot.setPosition({getPosition().x+30,getPosition().y});

    }
    else if(_rate == 2)
    {

    }

    else  if(_rate == 3)
    {

    }



}

void Robot::setRotationRight()
{
    _rate ++ ;
    this->_robot.setRotation(80);
    if(_rate > 5)
        _rate = 0;
}
void Robot::setRotationLeft()
{

    _rate --;

    if(_rate < -5)
        _rate = 0;
    this->_robot.rotate(60);

}

void Robot::setPosManually(sf::Vector2f f)
{
    _robot.setPosition(f);
}

sf::Vector2f Robot::getPosition()
{
    return this->_robot.getPosition();
}


