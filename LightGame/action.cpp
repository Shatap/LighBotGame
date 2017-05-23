#include "action.h"


Action::Action(int x, int y,Type_Action t)
    :_typeAction{t},_isClicked{false}
{
    _recAction.setPosition(x,y);
    _recAction.setFillColor(sf::Color::Green);
    _recAction.setSize(sf::Vector2f(_ACT_WIDTH,_ACT_HEIGHT ));

}

void Action::setRotation(Robot &r)
{

}

void Action::changeAltitude(Robot  &r)
{

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

