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

public:
    Level();
    Level(sf::RenderWindow& window);
    float setScore();
    float getScore() const;
    bool quit();
    void goToNextLevel();
    void replay();
    void launch_exec();
    void pause_exec();
    void loop() override;
    void displayLevelButtons();
    void mouse_button_pressed() override;
    void mouse_button_released() override;
};

#endif // LEVEL_H
