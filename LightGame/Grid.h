#ifndef GRID_H
#define GRID_H
#include "Hexagon.h"
#include "iostream"
#include "math.h"

/**
* Creates the Grid needed by the robot to move .
* The grid is composed of multiple hexagons
**/

class Grid
{
private:
    std::vector<Hexagon *> _grid;
    Hexagon *_hex;
    sf::RenderWindow m_window;
    const int GRID_SIZE =5;
     float _prevPosX ;
     float _prevPosY ;
     float _prevPosX2 ;
     float _prevPosY2;
public:

     /*!
      * DATE: 16/06/2017
      * BY: Yamin Tricha
      * --Grid Constructor--
      *
      * Creates GRID_SIZE * 6 Hexagon that will compose the grid
      *
      * No return Value
      */
    Grid()

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --Grid Destructor--
     *
     * Deallocate all the Hexagon Pointers
     *
     * No return Value
     */;
    ~Grid();


    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --display--
     *
     * displays all the Hexagons contained in the Grid Class vector.
     *
     * No return Value
     */
    void display(sf::RenderWindow &window);
    std::vector<Hexagon *> getGrid() const;


};

#endif // GRID_H
