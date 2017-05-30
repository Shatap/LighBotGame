#include "robot.h"

Robot::Robot():_rate{0}
{
    //_robot.setOutlineColor(sf::Color::Green);
    //_robot.setOutlineThickness(4);
    _robot.setRadius(20);
    _robot.setPosition({60,80});
    _robot.setOrigin({20,20});

//    _robot.rotate(60);



}

void Robot::draw_bot(sf::RenderWindow &w)
{
    sf::Texture texture;
    texture.loadFromFile("../LightGame/Sources/robot.png");
    _robot.setTexture(&texture);
    w.draw(_robot);
}

void Robot::bot_in_hex()
{

}

void Robot::setPosition()
{
        std::cout << "big booty babes " << _rate << std::endl;
    switch(_rate)
    {
    case 0:
        _robot.setPosition({getPosition().x+(30*cos(PI/3))+30,getPosition().y+(30*sin((PI)/3))});
        break;


    case 1:
    case -1:
        _robot.setPosition({getPosition().x,getPosition().y+(30*sin((PI)/3)+28)});

        break;

    case 2:
    case -2:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y+(30*sin((PI)/3))});

        break;

    case 3:
    case -3:
        break;

    case 4:
    case -4:
        _robot.setPosition({getPosition().x,getPosition().y-(30*sin((PI)/3)+28)});
        break;

    case 5:
    case -5:
        _robot.setPosition({getPosition().x+(30*cos(PI/3))+30,getPosition().y-(30*sin((PI)/3))});


        break;

    }

    if(_rate == 0 )
    {
    }

    else if(_rate == 1|| _rate == -1)
    {


    }
    else if(_rate == 2 || _rate == -2)
    {

    }

    else  if(_rate == 3)
    {

    }



}

void Robot::setRotationRight()
{
    _rate --;
    this->_robot.rotate(60);
    if(_rate < -5)
        _rate = 0;
//    _rate ++;
//    this->_robot.rotate(60);
//    if(_rate > 5)
//        _rate = 0;
}
void Robot::setRotationLeft()
{
        _rate ++;
        this->_robot.rotate(60);
        if(_rate > 5)
            _rate = 0;
//    _rate --;
//    this->_robot.rotate(60);
//    if(_rate < -5)
//        _rate = 0;
}

void Robot::setPosManually(sf::Vector2f f)
{
    _rate= 0;
    _robot.setPosition(f);
}

sf::Vector2f Robot::getPosition()
{
    return this->_robot.getPosition();
}


