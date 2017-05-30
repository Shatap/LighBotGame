#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>
#include "robot.h"
enum class Type_Action{forward,rotate_Right,rotate_Left,change_Altitude,sec_prog,light_Hex};
class Action
{
private:
    sf::RenderWindow m_window;

    const int _ACT_HEIGHT=40;
    const int _ACT_WIDTH=70;
    Type_Action _typeAction;
    sf::RectangleShape _recAction;
    int _rotateRate;
    sf::Texture _Forward;
    sf::Texture _RotateLeft;
    sf::Texture _RotateRight;
    sf::Texture _LightItUp;


public:
    Action(int x,int y,Type_Action t);
    ~Action();
    void setRotationLeft(Robot  &r);
    void setRotationRight(Robot &r);
    void changeAltitude(Robot  &r);
    void moveForward(Robot  &r);
    void lightHex(Robot &r, Grid &g, sf::RenderWindow &w);
    void displayAction(sf::RenderWindow  & window);
    sf::Texture getTexture();
    void setTexture(sf::Texture &t);
    void executeAction(Robot &r , Grid &g, sf::RenderWindow &w);
    sf::RectangleShape getDimension() const;
    void deleteAction();
    int getRotateRate() const;
};

#endif // ACTION_H
