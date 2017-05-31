#include "Primaryprog.h"

PrimaryProg::PrimaryProg()
    :Program{},_x_Pos{600},_y_Pos{200},_shift_X{600},_shift_Y{200}
{
    _primprog.setFillColor(sf::Color::White);
    _primprog.setSize({PROG_WIDTH,PROG_HEIGHT});
    _primprog.setOutlineThickness(3);
    _primprog.setOutlineColor(sf::Color::Black);
}

void PrimaryProg::addAction(Action  &action)
{
    _progActions.push_back(&action);
}

void PrimaryProg::resetVector()
{
    for(Action *a : _progActions)
    {
        a->deleteAction();
    }
    this->_progActions.erase(_progActions.cbegin(),_progActions.cend());
    _shift_X = _x_Pos;
    _shift_Y=_y_Pos;
}

void PrimaryProg::drawPrimProg(sf::RenderWindow & window)
{
    _primprog.setPosition({_x_Pos,_y_Pos});
    window.draw(_primprog);

}

std::vector<Action * > PrimaryProg::getPrimProg()
{
    return this->_progActions;
}

void PrimaryProg::executePrimProg(sf::RenderWindow &w, Robot &r,Grid & g)
{
    for(Action *a : _progActions)
    {

        a->executeAction(r,g,w);
        r.draw_bot(w);
    }
}

int PrimaryProg::getShift_X() const
{
    return _shift_X;
}


void PrimaryProg::setShift_X()
{
    _shift_X+=73;
    std::cout << _shift_X << std::endl;
    std::cout << _x_Pos << std::endl;

    if(_shift_X >= (_x_Pos + PROG_WIDTH) )
    {
        _shift_Y+=43;
        _shift_X=_x_Pos;

    }




}

int PrimaryProg::getShift_Y() const
{

    return _shift_Y;
}

bool PrimaryProg::isComplete()
{
    if(_shift_Y >= (PROG_WIDTH+((43)*3)))
    {

        return true == (_shift_Y >= (PROG_WIDTH+((43)*3)));
    }
}





