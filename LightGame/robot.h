#ifndef ROBOT_H
#define ROBOT_H
#include "robot.h"


class Robot
{
public:
    Robot();
    bool isMoving();
    int getAngle();
    int getAltitude();
};

#endif // ROBOT_H
