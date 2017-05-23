#ifndef PRIMARYPROG_H
#define PRIMARYPROG_H
#include"program.h"


class PrimaryProg:public Program
{
private:
    sf::RectangleShape _primprog;
    std::vector<Action*> _progActions;
public:
    PrimaryProg();
     std::vector<Action *>  addAction(Action &action) override;
     std::vector<Action *> removeAction(std::vector<Action *>)override;
     void drawPrimProg(sf::RenderWindow &window);
};

#endif // PRIMARYPROG_H
