#include <iostream>
#include "Grid.h"
#include "Menu.h"
#include "Level.h"

using namespace std;

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "LightBot", sf::Style::Close);
    Menu m(window);
    m.run();

    return 0;
}
