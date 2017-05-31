#ifndef ROBOT_H
#define ROBOT_H
#include "Application.h"
#include "Robot.h"
#include "Hexagon.h"
#include "Grid.h"
#include <SFML/Graphics.hpp>

/**
 * The Robot represents all the actions that will be chosen and executed by the user.
 * It's moves depends on the action stored and executed in the Prog.
 */

class Robot
{
private:
    sf::CircleShape _robot;
    Hexagon *_currenthex;
    int _rate;
    float const PI = 3.1415926;
    sf::Texture _downTexture;
    sf::Texture _sideTexture;
    bool _textureChange;
public:
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --Robot Constructor--
     *
     * Setup the dimension of the robot that will be created
     * on the grid
     *
     * No return Value
     */
    Robot();

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --draw_bot--
     * param:sf::RenderWindow &w
     *
     *Allows the display of the robot on the screen
     *
     * No return Value
     */
    void draw_bot(sf::RenderWindow &w);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --lightHex--
     * param: Robot &r ,Grid &g, sf::RenderWindow &w
     * Check all the hexagon on the grid , if the hexagon contains
     * the robot and is not lighted up yet , change it's color.
     *
     * No return Value
     */

    void lightHex(Grid &g, sf::RenderWindow &w);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --setPosition--
     * param:Grid &g
     * Depending on the _rate attribut (that changes each time the robot
     * does a rotation) and move the robot according to it .
     *
     * No return Value
     */

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --setRotationRight--
     *
     * Does a 60° rotation to the robot
     * and increments the _rate value by one
     *
     * No return Value
     */
    void setRotationRight();
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --setRotationLeft--
     *
     * Does a -60° rotation to the robot
     * and decrements the _rate value by one
     *
     * No return Value
     */
    void setRotationLeft();
    void setPosition(Grid &g);
    int getAngle();
    int getAltitude();
    sf::CircleShape getRobot();
    void setPosManually(sf::Vector2f);
    void setTexture(sf::Texture &t);



    sf::Vector2f getPosition();
};

#endif // ROBOT_H
