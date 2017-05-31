#ifndef PRIMARYPROG_H
#define PRIMARYPROG_H
#include"Program.h"
/**
 * The PrimaryProg class allow the user to put actions inside it , follow the execution of all the actions contained by
 * the Class vector
 */
class PrimaryProg: public Program
{
private:
    sf::RectangleShape _primprog;
    std::vector<Action*> _progActions;
    int _shift_X;
    int _shift_Y;
      int _x_Pos;
     int _y_Pos;
    const int PROG_WIDTH =363;
    const int PROG_HEIGHT=123;
public:
    PrimaryProg();

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --addAction--
     * param: Action &a
     * add the action in parameter to the Class vector
     *
     * No return Value
     */
    void addAction(Action &action) override;
    void removeAction(Action &action)override;

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --resetVector--
     * delete all the actions stored in the class vector     *
     *
     * No return Value
     */
    void resetVector();

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --drawPrimProg--
     * param: sf::RenderWindow &w
     * draw The Rectangle that contains will contains the actions
     * on the screen
     *
     * No return Value
     */
    void drawPrimProg(sf::RenderWindow &window);
    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --executePrimProg--
     * param: sf::RenderWindow &w, Robot &r, Grid &g
     *
     * execute all the actions stored in the class vector
     * No return Value
     */
    void executePrimProg(sf::RenderWindow &w, Robot &r, Grid &g);

    /*!
     * DATE: 16/06/2017
     * BY: Yamin Tricha
     * --isComplete--
     *
     * if the Class vector is considered full , refuse to add any action
     *
     * return a boolean
     */
    bool isComplete();


    std::vector<Action*> getPrimProg();
    int getShift_X() const;
    void setShift_X();
    int getShift_Y() const;


};

#endif // PRIMARYPROG_H
