#ifndef GRID_H
#define GRID_H
#include "hexagon.h"
#include "iostream"
#include "math.h"

class Grid
{
private:
    std::vector<Hexagon *> _grid;
    Hexagon *_hex;
    sf::RenderWindow m_window;
    const int GRID_SIZE =3;
     float _prevPosX ;
     float _prevPosY ;
     float _prevPosX2 ;
     float _prevPosY2;
public:
    Grid();
    ~Grid();
    void display(sf::RenderWindow &window);


};

#endif // GRID_H
