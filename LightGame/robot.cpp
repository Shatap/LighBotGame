#include "robot.h"

Robot::Robot():_rate{0}
{
    _robot.setRadius(10);
    _robot.setPosition({30,40});
    _robot.setOrigin({10,10});


    _robot.rotate(30);
    _robot.setScale(6,6);


    _sideTexture.loadFromFile("../LightGame/Sources/compass.png");
    _downTexture.loadFromFile("../LightGame/Sources/DownSprite.png");

}

void Robot::draw_bot(sf::RenderWindow &w)
{


        if(_textureChange)
        {
            setTexture(_sideTexture);
            w.draw(_robot);

        }

        else
        {
            setTexture(_downTexture);
std::cout << " AIZUDB AI9ZUDH AIUZHD IUAZHDI UHAZIUDH A ";
            w.draw(_robot);
            _textureChange = true;
        }



    sf::Texture texture;
    texture.loadFromFile("../LightGame/Sources/MainSprite.png");
    _robot.setTexture(&texture);
    _robot.setScale(3,3);
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
        _robot.setPosition({getPosition().x,getPosition().y+(30*sin((PI)/3)+28)});
        break;
    case -1:
        _robot.setPosition({getPosition().x,getPosition().y-(30*sin((PI)/3)+28)});
        break;

    case 2:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y-(30*sin((PI)/3))});
        break;
    case -2:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y+(30*sin((PI)/3))});
        break;

    case 3:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y+(30*sin((PI)/3))});
        break;
    case -3:
        _robot.setPosition({getPosition().x-((30*cos(PI/3))+30),getPosition().y-(30*sin((PI)/3))});
        break;

    case 4:
        _robot.setPosition({getPosition().x,getPosition().y-(30*sin((PI)/3)+28)});
        break;
    case -4:
        _robot.setPosition({getPosition().x,getPosition().y-(30*sin((PI)/3)+28)});
        break;

    case 5:
        _robot.setPosition({getPosition().x+(30*cos(PI/3))+30,getPosition().y+(30*sin((PI)/3))});
        break;
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

    std::cout<<_textureChange;
    if(_textureChange)
    {
        _textureChange=false;
    }

    else
        _textureChange=true;

}

void Robot::setRotationRight()
{

    _rate ++;
    this->_robot.rotate(60);
    if(_rate > 5)
        _rate = 0;
}
void Robot::setRotationLeft()
{

    _rate --;
    this->_robot.rotate(-60);
    if(_rate < -5)
        _rate = 0;

    std::cout << " RATE : " << _rate << std::endl;

}


void Robot::setPosManually(sf::Vector2f f)
{
    _robot.setPosition(f);
    _rate= 0;
}

void Robot::setTexture(sf::Texture & t)
{

        this->_robot.setTexture(&t);


}

sf::Vector2f Robot::getPosition()
{
    return this->_robot.getPosition();
}


