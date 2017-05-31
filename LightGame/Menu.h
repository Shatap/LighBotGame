#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Application.h"

/**
 * The class display a menu before the loading of the level,
 * allowing the user to either play or quit ...
 */

class Menu: public Application
{
private:
    void drawmenu(sf::RenderWindow &w);
    int _PLAY_WIDTH= 150;
    int _PLAY_HEIGHT= 75;
    int _QUIT_WIDTH= 150;
    int _QUIT_HEIGHT= 75;
    sf::RectangleShape _playbutton;
    sf::RectangleShape _quitbutton;
    sf::Texture _texture;
    sf::Texture _backgroundtexture;
    sf::Sprite _sprite;
    sf::Sprite _background;
    sf::Text _text_play;
    sf::Text _text_quit;
    sf::Font _button_font;
public:
    /*!
     * DATE: 05/29/2017
     * BY: Wyatt Reeves
     * --Menu Constructor--
     *
     * Sets up all the shapes needed to display the buttons of the menu
     *
     * param: sf::RenderWindow &w
     * No return Type
     */
    Menu(sf::RenderWindow& window);

    /*!
     * DATE: 05/23/2017
     * BY: Wyatt Reeves
     * --loop--
     *
     * inherit the loop method of the application class in
     * order to display the menu
     *
     * return a boolean
     */
    void loop() override;
    /*!
     * DATE: 05/23/2017
     * BY: Wyatt Reeves
     * --mouse_button_pressed--
     *
     * inherit the method of the Application class and
     * adapt it
     *
     * No return type
     */
    void mouse_button_pressed() override;
};

#endif // MENU_H
