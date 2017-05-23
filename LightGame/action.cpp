#include "action.h"


Action::Action(int x, int y,Type_Action t)
    :_typeAction{t},_isClicked{false}
{
    _recAction.setPosition(x,y);
    //_recAction.setFillColor(sf::Color::Green);
    _recAction.setSize(sf::Vector2f(_ACT_WIDTH,_ACT_HEIGHT ));
    sf::Texture texture;
    if(!texture.loadFromFile("/mnt/roon/users/ytricha/LighBotGame/LightGame/Sources/UP.jpg"))
    {
        std::cout <<" TGGGGGG ";
    }

    texture.bind();
    _recAction.setTexture(&texture);

}

void Action::setRotationLeft(Robot &r)
{
    if(this->_typeAction == Type_Action::rotate_Left)
        r.setRotationLeft();
}

void Action::setRotationRight(Robot &r)
{
    if(this->_typeAction == Type_Action::rotate_Left)
        r.setRotationRight();
}

void Action::changeAltitude(Robot  &r)
{
    if(this->_typeAction == Type_Action::change_Altitude)
    {

    }

}

void Action::moveForward(Robot  &r)
{

}

void Action::displayAction(sf::RenderWindow &window)
{
    window.draw(_recAction);

}

sf::RectangleShape  Action::getDimension() const
{
    return  _recAction;
}

