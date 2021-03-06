#ifndef PROGRAM_H
#define PROGRAM_H
#include "vector"
#include "Action.h"
/**
 * Abstract class that allow Primary And Secondary Prog Classes to inherit
 */
class  Program
{
private:
    const int SECONDARY_PROG_MAX = 10;
    int _num_actions;
    std::vector<Action *> _actions;
    Action* _action;
public:
    Program();
    virtual void  addAction(Action &action)=0;
};

#endif // PROGRAM_H
