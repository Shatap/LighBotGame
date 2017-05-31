#ifndef PRIMARYPROG_H
#define PRIMARYPROG_H
#include"program.h"

/*
* Classe abstraite qui fournit un modÃ ̈le de comportement
* pour les applications qui en hÃ©ritent
*
* Elle lance la boucle lecture des evenements/affichage,
* assure le décodage des événements et exÃ©cute
* les fonctions mouse_button_pressed, etc. qui sont
* (re) dÃ©finies dans les sous−classes, ainsi que
* (design pattern comportemental : "patron de méthodes")
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
    void addAction(Action &action) override;
    void removeAction(Action &action)override;
    void resetVector();
    void drawPrimProg(sf::RenderWindow &window);
    std::vector<Action*> getPrimProg();
    void executePrimProg(sf::RenderWindow &w, Robot &r, Grid &g);
    int getShift_X() const;
    void setShift_X();
    int getShift_Y() const;

    bool isComplete();

};

#endif // PRIMARYPROG_H
