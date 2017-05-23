#include "Application.h"
#include <iostream>
#include <math.h>       /* sqrt */

Application::Application(sf::RenderWindow &window)
    : _window(window)
{

}

void Application::stop() {
    m_running = false;
}

void Application::run()
{
    _window.setFramerateLimit(60);
    m_running = true;

    init();
    while (m_running) {
        process_events();
        loop();
    }
}

void Application::process_events()
{
    if (! _window.isOpen()) {
        stop();
        return;
    }

    while (_window.pollEvent(_event))
    {
        switch (_event.type)
        {
        case sf::Event::Closed :
            stop();
            break;
        case sf::Event::KeyPressed :
            key_pressed(_event.key);
            break;
        case sf::Event::MouseButtonPressed :
            // bouton = event.mouseButton.button;
            set_mouse_coord(_event.mouseButton.x, _event.mouseButton.y);
            mouse_button_pressed();
            break;
        case sf::Event::MouseMoved :
            set_mouse_coord(_event.mouseMove.x, _event.mouseMove.y);
            break;
        default:
            break;
        }
    }
}

/*
 * mémorisation de la position de la souris,
 * avec conversion de coordonnées  pixel -> fenetre
 */
void Application::set_mouse_coord(int x, int y)
{
    std::cout << "mouse : x : " << _mouse.x << ", y : " << _mouse.y << std::endl;
    auto pos = _window.mapPixelToCoords( {x, y});
    _mouse = { pos.x, pos.y };
}

/*
 * utilitaires (fonctions statiques)
 */
