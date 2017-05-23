#include "Menu.h"
#include "level.h"
#include <iostream>

bool ntm ;
Menu::Menu(sf::RenderWindow &window)
    : Application(window)
{
    _window.setTitle("Lightbot: Learn to code!");
    _button_font.loadFromFile("../LightGame/Sources/PenguinAttack.ttf");
    _playbutton.setPosition(425, 400);
    _playbutton.setFillColor(sf::Color::Green);
    _playbutton.setSize(sf::Vector2f(_PLAY_WIDTH, _PLAY_HEIGHT));
    _quitbutton.setPosition(425, 500);
    _quitbutton.setFillColor(sf::Color::Red);
    _quitbutton.setSize(sf::Vector2f(_QUIT_WIDTH, _QUIT_HEIGHT));
    _text_play.setPosition(425, 395);
    _text_play.setString("PLAY");
    _text_play.setFont(_button_font);
    _text_play.setCharacterSize(60);
    _text_quit.setPosition(425, 495);
    _text_quit.setFont(_button_font);
    _text_quit.setCharacterSize(60);
    _text_quit.setString("QUIT");
    if(!_texture.loadFromFile("/mnt/roon/users/wreeves/LightbotTitle.png"))
    {
        std::cout << "uh ooooooooooh" << std::endl;
    }

    _sprite.setTexture(_texture);
    _sprite.setPosition(190, 100);
}


void Menu::drawmenu(sf::RenderWindow &w) {
    w.draw(_playbutton);
    w.draw(_quitbutton);
    w.draw(_sprite);
    w.draw(_text_play);
    w.draw(_text_quit);
}


void Menu::loop()
{

    _window.clear(sf::Color::White);
    drawmenu(_window);
    _window.display();
}

void Menu::init()
{

}

void Menu::mouse_button_pressed()
{
    if(_playbutton.getGlobalBounds().contains(_mouse))
    {
        Level l(_window);
        _window.clear(sf::Color::White);
        l.run();
        _window.close();
    }
    if(_quitbutton.getGlobalBounds().contains(_mouse))
    {
        exit(0);
    }
}

void Menu::key_pressed(const sf::Event::KeyEvent &)
{

}

bool Menu::souris_dans_rectangle(const Position &coin, const Position &dims) const
{
    //    if(_mouse<= )
}
