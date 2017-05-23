#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>
#include "robot.h"
enum class Type_Action{forward,rotate,change_altitude,sec_prog};
class Action
{
private:
    sf::RenderWindow m_window;

    const int _ACT_HEIGHT=40;
    const int _ACT_WIDTH=70;
    Type_Action _typeAction;
    bool _isClicked;


public:
    sf::RectangleShape _recAction;
    Action(int x,int y,Type_Action t);
    void setRotation(Robot  &r);
    void changeAltitude(Robot  &r);
    void moveForward(Robot  &r);
    void displayAction(sf::RenderWindow  & window);
    //void executeAction();
    sf::RectangleShape getDimension() const;

};

#endif // ACTION_H
