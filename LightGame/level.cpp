#include "level.h"
#include "action.h"

Level::Level(sf::RenderWindow &window)
    : Application(window)
{
    _window.setTitle("Lightbot: Learn to code!");
    _grid = new Grid();

    _secProg = new ExecSecProg(1200,500,Type_Action::sec_prog);
    _changeAltitude = new Action(1200,400,Type_Action::change_altitude);
    _forward = new Action(1200,300,Type_Action::forward);
    _rotation = new Action(1200,200,Type_Action::rotate);
    _primaryProg = new PrimaryProg();

    _quit.setFillColor(sf::Color::Red);
    _quit.setPosition(1200,700);
    _quit.setSize({40,40});

    _actionPannel.push_back(_secProg);
    _actionPannel.push_back(_changeAltitude);
    _actionPannel.push_back(_forward);
    _actionPannel.push_back(_rotation);

}

void Level::loop()
{
    _window.clear(sf::Color::White);
    _forward->displayAction(_window);
    _rotation->displayAction(_window);
    _changeAltitude->displayAction(_window);
    _secProg->displayAction(_window);
    _grid->display(_window);
    displayLevelButtons();


    _rotation->displayAction(_window);
    _forward->displayAction(_window);
    _changeAltitude->displayAction(_window);
    _primaryProg->drawPrimProg(_window);

    _window.display();

    if(_changeAltitude->getDimension().getGlobalBounds().contains(_mouse))
    {
        _primaryProg->addAction()
    }







}



void Level::displayLevelButtons()
{
    _window.draw(_quit);

}



//bool Level::isMouseInEntity(const sf::Vector2i &mouse, const sf::FloatRect &entity)
//{

//    return  (mouse.y>=(entity.top) &&
//            (mouse.y <=entity.top+entity.height)&&
//            (mouse.x>=entity.left)&&
//            (mouse.x <=entity.left+entity.width));
//       std::cout << " EZZZZZZZZZZZZZZZ";

//}

//void Level::setMousePos(int x,int y)
//{
//    auto pos = _window.mapPixelToCoords( {x, y});
//    _mouse = { pos.x, pos.y };

//}
