#include "level.h"
#include "action.h"



Level::Level(sf::RenderWindow &window)
    : Application(window)
{
    _window.setTitle("Lightbot: Learn to code!");
    _grid = new Grid();

    _secProg = new ExecSecProg(1200,0,Type_Action::sec_prog);
    _changeAltitude = new Action(1200,80,Type_Action::change_Altitude);
    _forward = new Action(1200,160,Type_Action::forward);
    _rotation_Left = new Action(1200,240,Type_Action::rotate_Left);
    _rotation_Right = new Action(1200,320,Type_Action::rotate_Right);
    _light = new Action(1200,400,Type_Action::light_Hex);
    _primaryProg = new PrimaryProg();


    _quit.setFillColor(sf::Color::Red);
    _quit.setPosition(1200,600);
    _quit.setSize({60,40});

    _play.setFillColor(sf::Color::Black);
    _play.setPosition(1200,650);
    _play.setSize({60,40});

    _deleteVectorProg.setFillColor(sf::Color::Yellow);
    _deleteVectorProg.setPosition(1100,650);
    _deleteVectorProg.setSize({60,40});

    _actionPannel.push_back(_secProg);
    _actionPannel.push_back(_changeAltitude);
    _actionPannel.push_back(_forward);
    _actionPannel.push_back(_rotation_Right);
    _actionPannel.push_back(_rotation_Left);
    _actionPannel.push_back(_light);


    _robot = new Robot();
    _robot->setPosManually(_grid->getGrid().at(0)->getPosition());

    //  std::cout<< _grid->getGrid().at(2)->getPosition().x <<std::endl;

}

void Level::launch_exec()
{
    for(Action *a : _primaryProg->getPrimProg())
    {
        a->displayAction(_window);

        if (a->getDimension().getGlobalBounds().contains(_mouse))
        {

            a->deleteAction();
            //_primaryProg->removeAction(a);
        }

    }

}

void Level::loop()
{
    _window.clear(sf::Color::White);
    _forward->displayAction(_window);
    _rotation_Left->displayAction(_window);
    _rotation_Right->displayAction(_window);
    _changeAltitude->displayAction(_window);
    _light->displayAction(_window);
    _secProg->displayAction(_window);
    _grid->display(_window);
    _robot->draw_bot(_window);
    _primaryProg->drawPrimProg(_window);
    displayLevelButtons();



  //  mouse_button_pressed();
    launch_exec();
    //  std::cout<< "POSITIONNN : " << _grid->getGrid().at(2)->getPosition().x <<std::endl;
    // std::cout<< "ORIGINE " << _grid->getGrid().at(2)->getPosition().x <<std::endl;


    // std::cout << "X ROBOT " <<_robot->getPosition().x << std::endl;
    //  launch_exec();
    _window.display();



    //***** IMPLEMENTEZ UN BOUTON PLAY , QUI PARCOUR ET EXEC LE VECTEUR /////







}

void Level::mouse_button_pressed()
{
    if(_changeAltitude->getDimension().getGlobalBounds().contains(_mouse)&& !_primaryProg->isComplete() )
    {

        Action  *_ACA = new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::change_Altitude);
        _primaryProg->addAction(*_ACA);
        _primaryProg->setShift_X();




        std::cout<<"CHANGE ALTITUDE" << std::endl;

    }
    if(_forward->getDimension().getGlobalBounds().contains(_mouse)&& !_primaryProg->isComplete())
    {
        Action  *_AF = new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::forward);
        _primaryProg->addAction(*_AF);
        _primaryProg->setShift_X();

        std::cout<<"FORWARD" << std::endl;

    }

    if(_rotation_Left->getDimension().getGlobalBounds().contains(_mouse) && !_primaryProg->isComplete())
    {
        Action  *_ARL= new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::rotate_Left);
        _primaryProg->addAction(*_ARL);

        _primaryProg->setShift_X();
        std::cout<<"ROTATE LEFT " << std::endl;

    }

    if(_rotation_Right->getDimension().getGlobalBounds().contains(_mouse) && !_primaryProg->isComplete())
    {
        Action  *_ARR= new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::rotate_Right);
        _primaryProg->addAction(*_ARR);
        _primaryProg->setShift_X();
        std::cout<<"ROTATE RIGHT" << std::endl;

    }


    if(_light->getDimension().getGlobalBounds().contains(_mouse) && !_primaryProg->isComplete() )
    {        

        Action  *_AL= new Action(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::light_Hex);
        _primaryProg->addAction(*_AL);
        _primaryProg->setShift_X();
        std::cout<<"LIGHT_HEX" << std::endl;

    }

    if(_secProg->getDimension().getGlobalBounds().contains(_mouse)&& !_primaryProg->isComplete())
    {
        ExecSecProg *_SP = new ExecSecProg(_primaryProg->getShift_X(),_primaryProg->getShift_Y(),Type_Action::light_Hex);
        _primaryProg->addAction(*_SP);
        _primaryProg->setShift_X();
        std::cout<<"SEC PROOOG" << std::endl;

    }

    if(_quit.getGlobalBounds().contains(_mouse))
    {
        exit(0);
    }



    if(_deleteVectorProg.getGlobalBounds().contains(_mouse))
    {
        _primaryProg->resetVector();
        std::cout<< "POSITION HEX 1 : " <<_grid->getGrid().back()->getPosition().x << std::endl;
        _robot->setPosManually({_grid->getGrid().at(0)->getPosition()});
//        _robot->

    }
    if(_play.getGlobalBounds().contains(_mouse))
    {
        _primaryProg->executePrimProg(_window,*_robot,*_grid);

    }

    std::cout <<" PRIMARY PROG : " << _primaryProg->getPrimProg().size() << std::endl;

}

void Level::mouse_button_released()
{

}


void Level::displayLevelButtons()
{
    _window.draw(_play);

    _window.draw(_quit);
    _window.draw(_deleteVectorProg);

}




