#ifndef LEVEL_H
#define LEVEL_H
#include "vector"
#include "Robot.h"
#include "Grid.h"
#include "Action.h"
#include "Execsecprog.h"
#include "Application.h"
#include "Primaryprog.h"
#include "Robot.h"


class Level: public Application
{
private:
   // sf::RenderWindow _lwindow;
    std::vector<Level*>_levels;
    std::vector<Grid *> _gridslvl;
    std::vector<Action *> _actionPannel;
    Grid * _grid;
    float _score;
    Action *_rotation_Left ;
    Action *_rotation_Right;
    Action *_forward ;
    Action *_changeAltitude ;
    Action *_light;
    ExecSecProg  *_secProg;
    sf::RectangleShape _quit;
    sf::RectangleShape _play;
    sf::RectangleShape _deleteVectorProg;
    bool _isRunning = true;
    PrimaryProg * _primaryProg;
    Robot *_robot;
    sf::Color _color;
    sf::Texture _textureQuit;
    bool _isAllLighted;
    int _nbHexUnlighted;
    sf::RectangleShape _EndMenu;

public:
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --Level Constructor--
     *
     * Creates the whole level :
     * meaning the Grid, the Proc
     * and the buttons.
     *
     * No return Value
     */

    Level(sf::RenderWindow& window);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --setScore--
     *
     * set the Score of the player .
     *
     * No return Value
     */
    void setScore();

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --getScore--
     *
     * get the Score of the player .
     *
     * returns a float.
     */
    float getScore() const;


    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --launch_exec--
     *
     * displays the action pannel allowing the user to add actions.
     * delete the action if the user clicks on it .
     *
     * No return Value
     */
    void launch_exec();

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --loop--
     *
     * Manage the display of all the items displayed on the screen.
     *
     * No return Value
     */
    void loop() override;

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --displayLevelButtons--
     *
     * Creates the button Quit , ResetVector and Play .
     *
     * No return Value
     */
    void displayLevelButtons();

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --mouse_button_pressed();--
     *
     * manage all the interactions created by the user when a click is produced.
     *
     * No return Value
     */
    void mouse_button_pressed() override;


};

#endif // LEVEL_H
