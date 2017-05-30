#ifndef EXECSECPROG_H
#define EXECSECPROG_H
#include "action.h"

class ExecSecProg:public Action
{
private:
    std::vector<Action *> _secProg;
public:
    ExecSecProg(int x, int y,Type_Action t);

};

#endif // EXECSECPROG_H
