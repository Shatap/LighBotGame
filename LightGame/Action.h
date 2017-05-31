#ifndef ACTION_H
#define ACTION_H
#include <SFML/Graphics.hpp>
#include "Robot.h"

/**
 * Describe the Type of the actions that will be created .
 */
enum class Type_Action{forward,rotate_Right,rotate_Left,change_Altitude,sec_prog,light_Hex};

/**
 * This class represents an action that can be done by the robot.
 * It's a rectangleShape that will be checked by the program and it's content will be executed by the proc
 */
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

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --Action Constructor--
     * param: x int , y int , Type_Action t;
     * Creates an action depending on the x and y axis and the Type of the action .
     *
     * No return Value
     */
    Action(int x,int y,Type_Action t);


    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --setRotationLeft--
     * param: Robot &r     *
     * call the RotationLeft method of the robot
     *
     * No return Value
     */
    void setRotationLeft(Robot  &r);
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --setRotationRight--
     * param: Robot &r
     * call the RotationRight method of the robot
     *
     * No return Value
     */
    void setRotationRight(Robot &r);
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --changeAltitude(--
     * param: Robot &r
     * change the height where the Robot is supposed to be displayed
     * function not implemented yet .
     *
     * No return Value
     */
    void changeAltitude(Robot  &r);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --moveForward--
     * param: Robot &r , Grid &g
     * Call the MoveForward method of the robot
     *
     * No return Value
     */
    void moveForward(Robot  &r, Grid &g);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --lightHex--
     * param: Robot &r ,Grid &g, sf::RenderWindow &w
     * call the LightHex method of the robot
     *
     * No return Value
     */
    void lightHex(Robot &r, Grid &g, sf::RenderWindow &w);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --displayAction--
     * param: sf::RenderWindow &w
     * allows the display of the action on the screen
     *
     * No return Value
     */
    void displayAction(sf::RenderWindow  & window);
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --executeAction--
     * param: Robot &r ,Grid &g, sf::RenderWindow &w
     *
     * Calls the right method of execution depending on the Action_Type
     *
     * No return Value
     */
    void executeAction(Robot &r , Grid &g, sf::RenderWindow &w);

    void setTexture(sf::Texture &t);
    sf::RectangleShape getDimension() const;
    void deleteAction();
    int getRotateRate() const;
};

#endif // ACTION_H
