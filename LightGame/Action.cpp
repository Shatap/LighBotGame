#include "Action.h"




Action::Action(int x, int y,Type_Action t)
    :_typeAction{t},_rotateRate{0}

{
    _recAction.setPosition(x,y);
    _recAction.setSize(sf::Vector2f(_ACT_WIDTH,_ACT_HEIGHT ));
    _recAction.setOutlineThickness(2);
    _recAction.setOutlineColor(sf::Color::Black);
    _Forward.loadFromFile("../LightGame/Sources/Arrow.png");
    _RotateLeft.loadFromFile("../LightGame/Sources/RotateLeft.png");
    _RotateRight.loadFromFile("../LightGame/Sources/turnright.png");
    _LightItUp.loadFromFile("../LightGame/Sources/Light.png");


    switch(t)
    {
    case  Type_Action::forward:
        _recAction.setTexture(&_Forward);
        break;
    case Type_Action::rotate_Left:
        _recAction.setTexture(&_RotateLeft );

        break;
    case  Type_Action::rotate_Right:
        _recAction.setTexture(&_RotateRight);
        break;
    case Type_Action::light_Hex:
        _recAction.setTexture(&_LightItUp);
        break;
    }


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

void Action::moveForward(Robot &r,Grid & g)
{
    if(this->_typeAction == Type_Action::forward)
    {
        r.setPosition(g);
    }
}

void Action::lightHex(Robot &r, Grid &g,sf::RenderWindow &w)
{
        r.lightHex(g,w);
}

void Action::displayAction(sf::RenderWindow &window)
{

      window.draw(_recAction);

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



void Action::executeAction(Robot & r, Grid &g,sf::RenderWindow &w)
{
    Type_Action t;
    t= this->_typeAction;

    switch(t)
    {
    case  Type_Action::forward:
        moveForward(r,g);
        break;
    case Type_Action::rotate_Left:
        setRotationLeft(r);
        break;
    case  Type_Action::rotate_Right:
        setRotationRight(r);
        break;
    case Type_Action::light_Hex:
        lightHex(r,g,w);
        break;

    case Type_Action::sec_prog:

        break;

    case Type_Action::change_Altitude:
        changeAltitude(r);
        break;

    }

}
