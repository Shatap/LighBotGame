#include "robot.h"

Robot::Robot():_rate{0}
{
    _robot.setOutlineColor(sf::Color::Green);
    _robot.setOutlineThickness(4);
    _robot.setRadius(10);
    _robot.setPosition({60,80});
    _robot.setOrigin({20,20});
    _robot.setFillColor(sf::Color::Yellow);

//    _robot.rotate(60);



}

void Robot::draw_bot(sf::RenderWindow &w)
{
    sf::Texture texture;
    texture.loadFromFile("/mnt/roon/users/ytricha/LighBotGame/LightGame/Sources/robot.png");
    _robot.setTexture(&texture);
    w.draw(_robot);
}

bool Robot::bot_in_hex(Grid & g)
{

}

void Robot::lightHex(Grid &g, sf::RenderWindow &w)
{
    std::vector<Hexagon *> h = g.getGrid();
         for(Hexagon *he :h)
         {
            if (he->getHex().getGlobalBounds().contains(this->getPosition()))
            {
                if(he->getHex().getFillColor() == sf::Color::Blue)
                {

                    he->setColor(sf::Color::Red);
                    he->DrawHex(w);
                    std::cout<< he->getPosition().x << std::endl;
                    std::cout<< he->getPosition().y << std::endl;
                }

            }
         }
}

void Robot::setPosition(Grid &g)
{


    switch(_rate)
    {
    case 0:
        _robot.setPosition({getPosition().x+(30*cos(PI/3))+30,getPosition().y+(30*sin((PI)/3))});
        break;


    case 1:
    case -1:
        _robot.setPosition({getPosition().x,getPosition().y+(30*sin((PI)/3)+28)});
        break;

    case 2:
    case -2:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y+(30*sin((PI)/3))});
        break;

    case 3:
    case -3:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y-(30*sin((PI)/3))});
        break;

    case 4:
    case -4:
        _robot.setPosition({getPosition().x,getPosition().y-(30*sin((PI)/3)+28)});
        break;

    case 5:
    case -5:
        _robot.setPosition({getPosition().x+(30*cos(PI/3))+30,getPosition().y-(30*sin((PI)/3))});
        break;

    }


    int cpt = 0;
    for(Hexagon *hex : g.getGrid())
    {
        if(hex->getHex().getGlobalBounds().contains(this->getPosition()))
            cpt ++ ;
    }
    if(cpt == 0 )
    {
        this->setPosManually({100,100});
    }
}

void Robot::setRotationRight()
{
    _rate --;
    this->_robot.rotate(60);
    if(_rate < -5)
        _rate = 0;
//    _rate ++;
//    this->_robot.rotate(60);
//    if(_rate > 5)
//        _rate = 0;
}
void Robot::setRotationLeft()
{
        _rate ++;
        this->_robot.rotate(-60);
        if(_rate > 5)
            _rate = 0;
//    _rate --;
//    this->_robot.rotate(60);
//    if(_rate < -5)
//        _rate = 0;
}

void Robot::setPosManually(sf::Vector2f f)
{
    _rate= 0;
    _robot.setPosition(f);
}

sf::Vector2f Robot::getPosition()
{
    return this->_robot.getPosition();
}


