#ifndef LEVEL_H
#define LEVEL_H
#include "vector"
#include "robot.h"
#include "grid.h"
#include "action.h"
#include "execsecprog.h"
#include "Application.h"
#include "primaryprog.h"
#include "robot.h"


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
    ExecSecProg  *_secProg;
    sf::RectangleShape _quit;
    bool _isRunning = true;
    sf::FloatRect _QUIT_DIM ;
  //  sf::Vector2i _mouse;
    PrimaryProg * _primaryProg;
    Robot *_robot;

public:
    Level();
    Level(sf::RenderWindow& window);
    float setScore();
    float getScore();
    bool quit();
    void goToNextLevel();
    void replay();
    void pause_exec();
    void loop() override;
    void displayLevelButtons();
    void mouse_button_pressed() override;
    void mouse_button_released() override;
};

#endif // LEVEL_H
