#include "primaryprog.h"

PrimaryProg::PrimaryProg()
    :Program{}
{
    _primprog.setPosition({600,400});
    _primprog.setFillColor(sf::Color::White);
    _primprog.setSize({400,200});
    _primprog.setOutlineThickness(3);
    _primprog.setOutlineColor(sf::Color::Black);
}

std::vector<Action *> PrimaryProg::addAction(Action & action)
{
_progActions.push_back(action);

}

std::vector<Action *> PrimaryProg::removeAction(std::vector<Action *>)
{

}

void PrimaryProg::drawPrimProg(sf::RenderWindow & window)
{
    window.draw(_primprog);

}

