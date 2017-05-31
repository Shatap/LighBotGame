#include "Level.h"
#include "Action.h"



Level::Level(sf::RenderWindow &window)
    : Application(window),_isAllLighted{false}
{
    _window.setTitle("Lightbot: Learn to code!");
    _grid = new Grid();

    _forward = new Action(450,550,Type_Action::forward);
    _rotation_Left = new Action(550,550,Type_Action::rotate_Left);
    _rotation_Right = new Action(650,550,Type_Action::rotate_Right);
    _light = new Action(750,550,Type_Action::light_Hex);
    _primaryProg = new PrimaryProg();
    _color =  sf::Color(200,200,200);



    _quit.setPosition(1100,600);
    _quit.setSize({120,80});

    if(!_textureQuit.loadFromFile("../LightGame/Sources/quit.png"))
        std::cerr << "cant load image from path " << std::endl;

    if(!_textureplay.loadFromFile("../LightGame/Sources/Play.png"))
        std::cerr << "cant load image from path " << std::endl;

    if(!_restart.loadFromFile("../LightGame/Sources/restart.png"))
        std::cerr << "cant load image from path " << std::endl;


    _play.setPosition(800,300);
    _play.setSize({80,60});

    _deleteVectorProg.setPosition(800,400);
    _deleteVectorProg.setSize({60,40});
    _actionPannel.push_back(_forward);
    _actionPannel.push_back(_rotation_Right);
    _actionPannel.push_back(_rotation_Left);
    _actionPannel.push_back(_light);


    _robot = new Robot();
    _robot->setPosManually(_grid->getGrid().at(0)->getPosition());

}

Level::~Level()
{

}

void Level::launch_exec()
{
    for(Action *a : _primaryProg->getPrimProg())
    {
        a->displayAction(_window);

        if (a->getDimension().getGlobalBounds().contains(_mouse))
        {

            a->deleteAction();
        }

    }

}

void Level::loop()
{
    _window.clear(_color);
    _forward->displayAction(_window);
    _rotation_Left->displayAction(_window);
    _rotation_Right->displayAction(_window);
    _light->displayAction(_window);
    _grid->display(_window);
    _robot->draw_bot(_window);
    _primaryProg->drawPrimProg(_window);
    displayLevelButtons();




    launch_exec();

    if(_isAllLighted)
    {

        Menu m(_window);
        m.run();
        this->~Level();
    }
    _window.display();
}

void Level::mouse_button_pressed()
{
    if(_forward->getDimension().getGlobalBounds().contains(_mouse)&& !_primaryProg->isComplete())
    {
        Action  *_AF = new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::forward);
        _primaryProg->addAction(*_AF);
        _primaryProg->setShift_X();
    }

    if(_rotation_Left->getDimension().getGlobalBounds().contains(_mouse) && !_primaryProg->isComplete())
    {
        Action  *_ARL= new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::rotate_Left);
        _primaryProg->addAction(*_ARL);
        _primaryProg->setShift_X();
    }

    if(_rotation_Right->getDimension().getGlobalBounds().contains(_mouse) && !_primaryProg->isComplete())
    {
        Action  *_ARR= new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::rotate_Right);
        _primaryProg->addAction(*_ARR);
        _primaryProg->setShift_X();
    }


    if(_light->getDimension().getGlobalBounds().contains(_mouse) && !_primaryProg->isComplete() )
    {

        Action  *_AL= new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::light_Hex);
        _primaryProg->addAction(*_AL);
        _primaryProg->setShift_X();
    }

    if(_quit.getGlobalBounds().contains(_mouse))
    {
        exit(0);
    }



    if(_deleteVectorProg.getGlobalBounds().contains(_mouse))
    {
        _primaryProg->resetVector();
        _robot->setPosManually({_grid->getGrid().at(0)->getPosition()});
    }
    if(_play.getGlobalBounds().contains(_mouse))
    {
        _primaryProg->executePrimProg(_window,*_robot,*_grid);

        int cpt2=0;
        for(Hexagon * hex : _grid->getGrid())
        {
            if(hex->getColor()  == sf::Color::Blue)
            {
                cpt2 ++;
            }
            if(cpt2 == _grid->getGrid().size())
            {
                _isAllLighted = true;
            }



        }

    }

    for(Hexagon * hex :_grid->getGrid())
    {
        if(hex->getColor() == sf::Color::Green)
            _isAllLighted = true;
    }
}



void Level::displayLevelButtons()
{
    _quit.setTexture(&_textureQuit);
    _quit.setScale(1.2, 1.2);
    _play.setTexture(&_textureplay);
    _play.setScale(1.6,1.6);
    _deleteVectorProg.setTexture(&_restart);
    _deleteVectorProg.setScale(2,2);


    _window.draw(_play);
    _window.draw(_quit);
    _window.draw(_deleteVectorProg);

}





