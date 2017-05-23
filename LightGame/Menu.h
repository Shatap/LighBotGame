#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include "Application.h"

class Menu: public Application
{
private:
    //    sf::RenderWindow _window;
    void drawmenu(sf::RenderWindow &w);
    int _PLAY_WIDTH= 150;
    int _PLAY_HEIGHT= 75;
    int _QUIT_WIDTH= 150;
    int _QUIT_HEIGHT= 75;
    sf::RectangleShape _playbutton;
    sf::RectangleShape _quitbutton;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _text_play;
    sf::Text _text_quit;
    sf::Font _button_font;
public:
    Menu();
    Menu(sf::RenderWindow& window);
    //    sf::RectangleShape _playbutton;
    //    sf::RectangleShape _quitbutton;
    //    sf::Image _logo;
    void loop() override;
    void init() override;
    void mouse_button_pressed() override;
    void key_pressed(const sf::Event::KeyEvent &) override;
    bool souris_dans_rectangle(const Position & coin, const Position & dims) const;
};

#endif // MENU_H
