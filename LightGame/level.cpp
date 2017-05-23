#include "level.h"
#include "action.h"

bool mousedown = false;

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

    _robot = new Robot();
    std::cout<< _grid->getGrid().at(0)->getPosition().x <<std::endl;
}
//bool Level::quit()
//{
//    if(isMouseInEntity(_mouse,_QUIT_DIM))
//        return _isRunning=false;    draw_bot(_window);

//}
void Level::loop()
{
    _window.clear(sf::Color::White);
    _forward->displayAction(_window);
    _rotation->displayAction(_window);
    _changeAltitude->displayAction(_window);
    _secProg->displayAction(_window);
    _grid->display(_window);
    displayLevelButtons();
    _robot->draw_bot(_window);

    //        if(sf::Event::MouseButtonPressed)
    //        {
    //            setMousePos(event.mouseButton.x,event.mouseButton.y);
    //            std::cout<<_mouse.x<<std::endl;
    //        }



    _rotation->displayAction(_window);
    _forward->displayAction(_window);
    _changeAltitude->displayAction(_window);
    _primaryProg->drawPrimProg(_window);
    mouse_button_pressed();
    _robot->setPosition(_grid->getGrid().at(10));
    std::cout<< "POSITIONNN : " << _grid->getGrid().at(0)->getPosition().x <<std::endl;
    std::cout<< "ORIGINE " << _grid->getGrid().at(0)->getPosition().x <<std::endl;


    _window.display();




}

void Level::mouse_button_pressed()
{
    if(_changeAltitude->getDimension().getGlobalBounds().contains(_mouse))
    {
        mousedown = true;
        std::cout << mousedown << std::endl;
        Action  *_CA = new Action(45,45,Type_Action::change_altitude);
        _actionPannel.push_back(_CA);
        std::cout<<"CHANGE ALTITUDE" << std::endl;

    }
    if(_forward->getDimension().getGlobalBounds().contains(_mouse))
    {
        Action  *_AF = new Action(45,45,Type_Action::forward);
        _actionPannel.push_back(_AF);
        std::cout<<"FORWARD" << std::endl;

    }

    if(_rotation->getDimension().getGlobalBounds().contains(_mouse) && sf::Event::MouseButtonPressed)
    {
        Action  *_AR= new Action(45,45,Type_Action::rotate);
        _actionPannel.push_back(_AR);
        std::cout<<"ROTATE" << std::endl;

    }

    if(_quit.getGlobalBounds().contains(_mouse))
    {
        exit(0);
    }

}

void Level::mouse_button_released()
{

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
