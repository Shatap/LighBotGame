#include "action.h"




Action::Action(int x, int y,Type_Action t)
    :_typeAction{t},_rotateRate{0}

{
    _recAction.setPosition(x,y);
    _recAction.setSize(sf::Vector2f(_ACT_WIDTH,_ACT_HEIGHT ));
    _recAction.setOutlineThickness(2);
    _recAction.setOutlineColor(sf::Color::Black);
    _Forward.loadFromFile("../LightGame/Sources/arrow.png");
    _Rotateleft.loadFromFile("../LightGame/Sources/RotateLeft.png");
    _Rotateright.loadFromFile("../LightGame/Sources/RotateRight.png");
    _Lightitup.loadFromFile("../LightGame/Sources/Light.png");


    switch(t)
    {
    case  Type_Action::forward:
        _recAction.setTexture(&_Forward, false);

        break;
    case Type_Action::rotate_Left:
        _recAction.setTexture(&_Rotateleft, false);
        break;
    case  Type_Action::rotate_Right:
        _recAction.setTexture(&_Rotateright, false);
        break;
    case Type_Action::light_Hex:
        _recAction.setTexture(&_Lightitup, false);
        break;

    case Type_Action::sec_prog:
        _recAction.setFillColor(sf::Color::Red);
        break;

    case Type_Action::change_Altitude:
        _recAction.setFillColor(sf::Color::Green);
        break;

    }


}

Action::~Action()
{

}

void Action::setRotationLeft(Robot &r)
{
    if(this->_typeAction == Type_Action::rotate_Left)
    {
        _rotateRate++;
        r.setRotationLeft();
    }

}

void Action::setRotationRight(Robot &r)
{
    if(this->_typeAction == Type_Action::rotate_Right)
    {
        _rotateRate--;
        r.setRotationRight();
    }
}

void Action::changeAltitude(Robot  &r)
{


}

void Action::moveForward(Robot &r)
{
    if(this->_typeAction == Type_Action::forward)
    {
        r.setPosition();
    }
}

void Action::lightHex(Robot &r)
{

}

void Action::displayAction(sf::RenderWindow &window)
{

    Type_Action t = this->_typeAction;


      window.draw(_recAction);

}

sf::Texture  Action::getTexture()
{
   /* Type_Action t = this->_typeAction;
    switch(t)
    {
    case  Type_Action::forward:
    {
        sf::Texture texture;
        texture.loadFromFile("/home/Oka/LighBotGame/LightGame/Sources/UP.jpg");
        return texture;
        break;
    }
    case Type_Action::rotate_Left:
        _recAction.setFillColor(sf::Color::Blue);
        break;
    case  Type_Action::rotate_Right:
        _recAction.setFillColor(sf::Color::Yellow);
        break;
    case Type_Action::light_Hex:
        _recAction.setFillColor(sf::Color::Magenta);
        break;

    case Type_Action::sec_prog:
        _recAction.setFillColor(sf::Color::Red);
        break;

    case Type_Action::change_Altitude:
        _recAction.setFillColor(sf::Color::Green);
        break;


    }*/
}

void Action::setTexture(sf::Texture &t)
{
    this->_recAction.setTexture(&t);
}

sf::RectangleShape Action::getDimension() const
{
    return  _recAction;
}

void Action::deleteAction()
{
    this->_recAction.setFillColor(sf::Color::White);

}

int Action::getRotateRate() const
{
    return _rotateRate;
}



void Action::executeAction(Robot & r)
{
    Type_Action t;
    t= this->_typeAction;

    switch(t)
    {
    case  Type_Action::forward:
        moveForward(r);
        break;
    case Type_Action::rotate_Left:
        setRotationLeft(r);
        break;
    case  Type_Action::rotate_Right:
        setRotationRight(r);
        break;
    case Type_Action::light_Hex:
        lightHex(r);
        break;

    case Type_Action::sec_prog:

        break;

    case Type_Action::change_Altitude:
        changeAltitude(r);
        break;

    }

}
