#ifndef PROGRAM_H
#define PROGRAM_H
#include "vector"
#include "action.h"

class  Program
{
private:
    const int SECONDARY_PROG_MAX = 10;
    int _num_actions;
    std::vector<Action *> _actions;
    Action* _action;
public:
    Program();
    virtual std::vector<Action *>  addAction(std::vector<Action *>)=0;
    virtual std::vector<Action *>  removeAction(std::vector<Action *>)=0;

};

#endif // PROGRAM_H
