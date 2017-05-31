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

        sf::Event event;

        switch (_event.type)
        {
        case sf::Event::Closed :
            stop();
            break;
        case sf::Event::KeyPressed :
            key_pressed(_event.key);
            break;
        case sf::Event::MouseButtonPressed :
            set_mouse_coord(_event.mouseButton.x, _event.mouseButton.y);
            mouse_button_pressed();
            break;
        case sf::Event::MouseButtonReleased :
            set_mouse_coord(event.mouseButton.x, event.mouseButton.y);
            mouse_button_released();
            break;
        case sf::Event::MouseMoved :
            set_mouse_coord(_event.mouseMove.x, _event.mouseMove.y);
            break;
        default:
            break;
        }
    }
}


void Application::set_mouse_coord(int x, int y)
{
    auto pos = _window.mapPixelToCoords( {x, y});
    _mouse = { pos.x, pos.y };
}


