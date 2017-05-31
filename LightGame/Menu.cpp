#include "Menu.h"
#include "Level.h"
#include <iostream>

Menu::Menu(sf::RenderWindow &window)
    : Application(window)
{
    _window.setTitle("Lightbot: Learn to code!");
    _button_font.loadFromFile("../LightGame/Sources/8bitOperatorPlusSC-Bold.ttf");
    _playbutton.setPosition(565, 400);
    _playbutton.setFillColor(sf::Color(173,13,13));
    _playbutton.setSize(sf::Vector2f(_PLAY_WIDTH, _PLAY_HEIGHT));
    _quitbutton.setPosition(565, 500);
    _quitbutton.setFillColor(sf::Color(84,84,84));
    _quitbutton.setSize(sf::Vector2f(_QUIT_WIDTH, _QUIT_HEIGHT));
    _text_play.setPosition(_playbutton.getPosition());
    _text_play.setString("PLAY");
    _text_play.setFont(_button_font);
    _text_play.setCharacterSize(55);
    _text_quit.setPosition(_quitbutton.getPosition());
    _text_quit.setFont(_button_font);
    _text_quit.setCharacterSize(55);
    _text_quit.setString("QUIT");
    if(!_texture.loadFromFile("../LightGame/Sources/LightGameTitle.png"))
    {
        std::cerr << "cant load the Game Title" << std::endl;
    }
    if(!_backgroundtexture.loadFromFile("../LightGame/Sources/background.png"))
    {
        std::cerr << "whoopsy daisy " << std::endl;
    }
    _background.setTexture(_backgroundtexture);
    _sprite.setTexture(_texture);
    _sprite.setPosition(125,-150);
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


