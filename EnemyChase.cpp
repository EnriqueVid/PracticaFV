/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EnemyChase.cpp
 * Author: newman
 * 
 * Created on 26 de abril de 2018, 23:02
 */

#include "EnemyChase.h"
#include "Player.h"


EnemyChase::EnemyChase(Texture* tex, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale, string pattern, float loop): Enemy(tex, origin, position, scale) 
{
    _pattern = pattern;
    _cone = new Sprite(tex, sf::IntRect(160, 112, 96, 144), sf::Vector2f(48.0f,0.0f), position, scale);
    _cone->setSpriteColor(255,255,255,100);
    _actualStep = 0;
    _state = 0;
    setEnemySpeed(4);
    _loop = loop;
    _stopClock = NULL;
    _chaseClock = NULL;
    _loopClock = new Clock();
    _counter = 10;
    _path = NULL;
    _pathDim = 0;
    _pathPos = 0;
    _initPos.x = position.x;
    _initPos.y = position.y;
    _astar = NULL;
}

EnemyChase::EnemyChase(const EnemyChase& orig) {
}

EnemyChase::~EnemyChase() 
{
    //se llama al destructor de padre
    if(_cone!=NULL)
    {
        delete _cone;
        _cone=NULL;
    }
    if(_chaseClock!=NULL)
    {
        delete _chaseClock;
        _chaseClock=NULL;
    }
    if(_loopClock!=NULL)
    {
        delete _loopClock;
        _loopClock=NULL;
    }
    if(_stopClock!=NULL)
    {
        delete _stopClock;
        _stopClock=NULL;
    }
    
    if(_astar != NULL)
    {
        delete _astar;
        _astar = NULL;
    }
    
    if(_path != NULL)
    {
        delete _path;
        _path = NULL;
    }
    
    
}

void EnemyChase::update(int** map, int height, int width)
{
    setEnemyPreviousSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle());
    
    if(_state!=2){
        if(getCollisionPlayer())
        {
            _state = 1;
        }
        setCollisionPlayer(false);
    }
    
    if(_collisionBullet)
    {
        _state = 2;   
        _collisionBullet = false;
    }
    
    if(_state == 0)
    {
        updateStateIdle(map);
    }
    else if(_state == 1)
    {
        updateStateChase(map, height, width);
    }
    else if(_state == 2)
    {
        updateStateStop();
    }
    else if(_state == 3)
    {
        returnHome(map, height, width);
    }
}

void EnemyChase::updateStateIdle(int** map)
{
    if(_actualStep >= _pattern.length()) _actualStep = 0;
    
    switch(_pattern.at(_actualStep))
    {
        case 'u':
            if(getEnemyActualSituation()->getAngle() < 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
            }
            else if(getEnemyActualSituation()->getAngle() > 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else
            {
                if(map[int(getEnemyActualSituation()->getPosition().y-16-getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x-16)/32] == 2 || map[int(getEnemyActualSituation()->getPosition().y-16-getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x+16)/32] == 2)
                {
                    sf::Vector2f aux;
                    while(map[int(getEnemyActualSituation()->getPosition().y-17)/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 && map[int(getEnemyActualSituation()->getPosition().y-17)/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
                    {
                        aux.x = getEnemyActualSituation()->getPosition().x;
                        aux.y = getEnemyActualSituation()->getPosition().y-1;
                        setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                    }
                }
                else
                {
                    enemyMove(sf::Vector2f(0.0f, -1.0f), 180.0f);
                }
            }
            
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        case 'd':
            if(getEnemyActualSituation()->getAngle() > 0 && getEnemyActualSituation()->getAngle() <= 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else if(getEnemyActualSituation()->getAngle() < 360 && getEnemyActualSituation()->getAngle() > 180)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
                
            }
            else
            {
                if(map[int(getEnemyActualSituation()->getPosition().y+16+getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x-16)/32] == 2 || map[int(getEnemyActualSituation()->getPosition().y+16+getEnemySpeed())/32][int(getEnemyActualSituation()->getPosition().x+16)/32] == 2)
                {
                    sf::Vector2f aux;
                    while(map[int(getEnemyActualSituation()->getPosition().y+17)/32][int(getEnemyActualSituation()->getPosition().x-16)/32] != 2 && map[int(getEnemyActualSituation()->getPosition().y+17)/32][int(getEnemyActualSituation()->getPosition().x+16)/32] != 2)
                    {
                        aux.x = getEnemyActualSituation()->getPosition().x;
                        aux.y = getEnemyActualSituation()->getPosition().y+1;
                        setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                    }
                }
                else
                {
                    enemyMove(sf::Vector2f(0.0f, 1.0f), 0.0f);
                }
            }
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        case 'l':
            if(getEnemyActualSituation()->getAngle() > 90 && getEnemyActualSituation()->getAngle() <= 270)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else if(getEnemyActualSituation()->getAngle() < 90 || getEnemyActualSituation()->getAngle() > 270)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
            }
            else
            {
                if(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x-16-getEnemySpeed())/32] == 2 || map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x-16-getEnemySpeed())/32] == 2)
                {
                    sf::Vector2f aux;
                    while(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x-17)/32] != 2 && map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x-17)/32] != 2)
                    {
                        aux.x = getEnemyActualSituation()->getPosition().x-1;
                        aux.y = getEnemyActualSituation()->getPosition().y;
                        setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                    }
                }
                else
                {
                    enemyMove(sf::Vector2f(-1.0f, 0.0f), 90.0f);
                }
            }
            
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        case 'r':
            if(getEnemyActualSituation()->getAngle() < 270 && getEnemyActualSituation()->getAngle() >= 90)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()+5);
            }
            else if(getEnemyActualSituation()->getAngle() > 270 || getEnemyActualSituation()->getAngle() < 90)
            {
                setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle()-5);
            }
            else
            {
                if(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x+16+getEnemySpeed())/32] == 2 || map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x+16+getEnemySpeed())/32] == 2)
                {
                    sf::Vector2f aux;
                    while(map[int(getEnemyActualSituation()->getPosition().y+16)/32][int(getEnemyActualSituation()->getPosition().x+17)/32] != 2 && map[int(getEnemyActualSituation()->getPosition().y-16)/32][int(getEnemyActualSituation()->getPosition().x+17)/32] != 2)
                    {
                        aux.x = getEnemyActualSituation()->getPosition().x+1;
                        aux.y = getEnemyActualSituation()->getPosition().y;
                        setEnemyActualSituation(aux, getEnemyActualSituation()->getAngle());
                    }
                }
                else
                {
                    enemyMove(sf::Vector2f(1.0f, 0.0f), 270.0f);
                }
            }
            
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
            
        default:
            if(_loopClock->getClockAsSeconds()>=_loop)
            {
                _actualStep++;
                _loopClock->clockRestart();
            }
            break;
    }
    if(getEnemyActualSituation()->getAngle() < 0) setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle() + 360);
    if(getEnemyActualSituation()->getAngle() > 360) setEnemyActualSituation(getEnemyActualSituation()->getPosition(), getEnemyActualSituation()->getAngle() - 360);
}

void EnemyChase::updateStateChase(int** map, int height, int width)
{
    if(getCollisionPlayer())
    {
        if(_chaseClock!=NULL)
        {
            _chaseClock->clockRestart();
        }
        setCollisionPlayer(false);
    }    
    
    if(_chaseClock == NULL) _chaseClock = new Clock;
    
    if(_chaseClock->getClockAsSeconds() <= 10.0f)
    {
        float catC, catO, catCE, catOE, hipo, hipoE, rot, pathX, pathY, eneX, eneY;
        int axisX, axisY;
        std::string way = "";
        Player* p = Player::Instance();
        eneX = getEnemyActualSituation()->getPositionX();
        eneY = getEnemyActualSituation()->getPositionY();
        
        if((eneX < p->getActualSituation()->getPositionX()+64 && eneX > p->getActualSituation()->getPositionX()-64) && (eneY < p->getActualSituation()->getPositionY()+64 && eneY > p->getActualSituation()->getPositionY()-64))
        {
            cout<<"Ya estoy mu cerca bro"<<endl;
            catCE = eneX-p->getActualSituation()->getPositionX();
            catOE = eneY-p->getActualSituation()->getPositionY();
            hipoE = sqrt((catCE*catCE)+(catOE*catOE));
            
            if(eneY > p->getActualSituation()->getPositionY())
            {
                rot = (3.14159265359/2+acos(catCE/hipoE))*180/3.14159265359;
            }
            else
            {
                rot = (3.14159265359/2-acos(catCE/hipoE))*180/3.14159265359;
            }
            enemyMove(sf::Vector2f(0, 0),rot);
            
        }
        else
        { 
            if(_counter >9)
            {
                _counter = 0;
                if(_astar != NULL) delete _astar;
                _astar = new Astar(map, height, width, 4);

                way = _astar->pathfind(sf::Vector2i((int)getEnemyActualSituation()->getPositionX()/32, (int)getEnemyActualSituation()->getPositionY()/32),sf::Vector2i((int)p->getActualSituation()->getPositionX()/32, (int)p->getActualSituation()->getPositionY()/32));
                _path = _astar->getAbsoluto(way);
                cout<<"way: "<<way<<endl;

                _pathDim = way.size();
                _pathPos = 0;

            }else
            {
                if(_pathDim != 0)
                    _counter++;
                else
                    _counter = 10;
            }

            pathX = _path[_pathPos].x*32+16;
            pathY = _path[_pathPos].y*32+16;

            if((eneX < pathX+2 && eneX > pathX-2) && (eneY < pathY+2 && eneY > pathY-2))
            {
                _pathPos ++;
                pathX = _path[_pathPos].x*32+16;
                pathY = _path[_pathPos].y*32+16;
            }
            /*
            cout<<"_pathDim: "<<_pathDim<<endl;
            bool aux = false;
            for(int y=0; y<height; y++)
            {
                for(int x=0; x<width; x++)
                {
                    if((int)eneX/32 == x && (int)eneY/32 == y)
                    {
                        cout<<"E";
                        aux = true;
                    }
                    if((int)p->getActualSituation()->getPositionX()/32 == x && (int)p->getActualSituation()->getPositionY()/32 == y && aux == false)
                    {
                        cout<<"J";
                        aux = true;
                    }
                    for(int i=0; i<_pathDim; i++)
                    {
                        if(_path[i].x == x && _path[i].y == y && aux == false)
                        {
                            cout<<"X";
                            aux = true;
                        }
                    }
                    if(aux == false) cout<<map[y][x];
                    aux = false;
                }
                cout<<endl;
            }
            */
            catC = pathX-eneX;
            catO = pathY-eneY;
            hipo = sqrt((catC*catC)+(catO*catO));
            catCE = eneX-p->getActualSituation()->getPositionX();
            catOE = eneY-p->getActualSituation()->getPositionY();
            hipoE = sqrt((catCE*catCE)+(catOE*catOE));
            
            
            if(eneY > p->getActualSituation()->getPositionY())
            {
                rot = (3.14159265359/2+acos(catCE/hipoE))*180/3.14159265359;
            }
            else
            {
                rot = (3.14159265359/2-acos(catCE/hipoE))*180/3.14159265359;
            }
            enemyMove(sf::Vector2f(catC/hipo, catO/hipo),rot);
            
            axisX = 0;
            axisY = 0;
            
            if(getEnemyActualSituation()->getPositionX()-getEnemyPreviousSituation()->getPositionX() > 0) axisX = 1;
            if(getEnemyActualSituation()->getPositionX()-getEnemyPreviousSituation()->getPositionX() < 0) axisX = -1;
            if(getEnemyActualSituation()->getPositionY()-getEnemyPreviousSituation()->getPositionY() > 0) axisY = 1;
            if(getEnemyActualSituation()->getPositionY()-getEnemyPreviousSituation()->getPositionY() < 0) axisY = -1;
            
            mapCollisions(map, axisX, axisY);
        }
    }
    else
    {
        delete _chaseClock;
        _chaseClock = NULL;
        _state = 3;
        setEnemyActualSituation(getEnemyActualSituation()->getPosition(), int(getEnemyActualSituation()->getAngle())/5*5);
        setCollisionPlayer(false);
        //cout<<int(getEnemyActualSituation()->getAngle())<<endl;
    }
}

void EnemyChase::updateStateStop()
{
    if(_stopClock == NULL) _stopClock = new Clock();
    if(_stopClock != NULL && _stopClock->getClockAsSeconds() > 15)
    {
        _state = 3;
        delete _stopClock;
        _stopClock = NULL;
        _cone->setSpriteColor(255, 255, 255, 100);
        
    }
    else
    {
        _cone->setSpriteColor(255, 255, 255, 0);
    }
}

void EnemyChase::enemyChaseCollision()
{
    
}
    
void EnemyChase::setEnemyChasePattern(string pattern)
{
    _pattern = pattern;
}

void EnemyChase::setEnemyState(int s)// s=0 ==> Idle; s=1 ==> Mirar; s=2 ==> Paralizado
{
    _state = s;
}
    
string EnemyChase::getEnemyChasePattern()
{
    return _pattern;
}
    
Sprite* EnemyChase::getConeSprite()
{
    return _cone;
}

void EnemyChase::mapCollisions(int** map, int axisX, int axisY)
{
    float auxX = getEnemyActualSituation()->getPositionX();

        if(axisX>0)
        {
            if(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] == 2 || map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] == 2)

            {
                getEnemyActualSituation()->setPosition(getEnemyPreviousSituation()->getPositionX(),getEnemyActualSituation()->getPositionY());

                while(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()+15)/32] != 2 && map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()+15)/32] != 2)
                {
                    getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX()+1,getEnemyActualSituation()->getPositionY());
                }

            }
        }

        else if(axisX<0)
         {
            if(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] == 2 || map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] == 2)

            {
                getEnemyActualSituation()->setPosition(getEnemyPreviousSituation()->getPositionX(),getEnemyActualSituation()->getPositionY());

                while(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()-15)/32] != 2 && map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()-15)/32] != 2)
                {
                    getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX()-1,getEnemyActualSituation()->getPositionY());
                }

            }

        }
        if(axisY>0)
        {
            if(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] == 2 || map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] == 2)
            {
                getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX(),getEnemyPreviousSituation()->getPositionY());

                while(map[int(getEnemyActualSituation()->getPositionY()+15)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] != 2 && map[int(getEnemyActualSituation()->getPositionY()+15)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] != 2)
                {
                    getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX(),getEnemyActualSituation()->getPositionY()+1);
                }
            }
        }
        else if(axisY<0)
        {
            if(map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] == 2 || map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] == 2)
            {
                getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX(),getEnemyPreviousSituation()->getPositionY());

                while(map[int(getEnemyActualSituation()->getPositionY()-15)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] != 2 && map[int(getEnemyActualSituation()->getPositionY()-15)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] != 2)
                {
                    getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX(),getEnemyActualSituation()->getPositionY()-1);
                }
            }
        }

        if((getEnemyPreviousSituation()->getPositionX() == getEnemyActualSituation()->getPositionX() && auxX != getEnemyActualSituation()->getPositionX()))
        {
            getEnemyActualSituation()->setPosition(auxX, getEnemyActualSituation()->getPositionY());
            if(axisX>0)
            {
                if(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] == 2 || map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()+14)/32] == 2)
                {
                    auxX = getEnemyActualSituation()->getPositionX()+14;
                    getEnemyActualSituation()->setPosition(getEnemyPreviousSituation()->getPositionX(),getEnemyActualSituation()->getPositionY());

                    while(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()+15)/32] != 2 && map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()+15)/32] != 2)
                    {
                        getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX()+1,getEnemyActualSituation()->getPositionY());
                    }

                }
            }
            else if(axisX<0)
             {
                if(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] == 2 || map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()-14)/32] == 2)
                {
                    auxX = getEnemyActualSituation()->getPositionX()-14;
                    getEnemyActualSituation()->setPosition(getEnemyPreviousSituation()->getPositionX(),getEnemyActualSituation()->getPositionY());

                    while(map[int(getEnemyActualSituation()->getPositionY()+14)/32][int(getEnemyActualSituation()->getPositionX()-15)/32] != 2 && map[int(getEnemyActualSituation()->getPositionY()-14)/32][int(getEnemyActualSituation()->getPositionX()-15)/32] != 2)
                    {
                        getEnemyActualSituation()->setPosition(getEnemyActualSituation()->getPositionX()-1,getEnemyActualSituation()->getPositionY());
                    }
                }
            }
        }
}

void EnemyChase::setCollisionBullet(bool b)
{
    _collisionBullet = b;
}

void EnemyChase::returnHome(int** map, int height, int width)
{
    std::string way = "";
    float catC, catO, catCE, catOE, hipo, hipoE, rot, pathX, pathY, eneX, eneY;
    int axisX, axisY;
    eneX = getEnemyActualSituation()->getPositionX();
    eneY = getEnemyActualSituation()->getPositionY();
        if(_counter >9)
        {
            if(_astar != NULL) delete _astar;
            _counter = 0;
            _astar = new Astar(map, height, width, 4);
            way = _astar->pathfind(sf::Vector2i((int)getEnemyActualSituation()->getPositionX()/32, (int)getEnemyActualSituation()->getPositionY()/32),sf::Vector2i((int)_initPos.x/32, (int)_initPos.y/32));
            _path = _astar->getAbsoluto(way);
            cout<<"way: "<<way<<endl;
            _pathDim = way.size();
            _pathPos = 0;
            
        }else
        {
            if(_pathDim != 0)
                _counter++;
            else
                _counter = 10;
        }

        pathX = _path[_pathPos].x*32+16;
        pathY = _path[_pathPos].y*32+16;

        if(_pathDim > 0)
        {
            if((eneX < pathX+2 && eneX > pathX-2) && (eneY < pathY+2 && eneY > pathY-2))
            {
                _pathPos ++;
                pathX = _path[_pathPos].x*32+16;
                pathY = _path[_pathPos].y*32+16;
            }

            catC = pathX-eneX;
            catO = pathY-eneY;
            hipo = sqrt((catC*catC)+(catO*catO));
            catCE = eneX-_initPos.x;
            catOE = eneY-_initPos.y;
            hipoE = sqrt((catCE*catCE)+(catOE*catOE));


            if(eneY > _initPos.y)
            {
                rot = (3.14159265359/2+acos(catCE/hipoE))*180/3.14159265359;
            }
            else
            {
                rot = (3.14159265359/2-acos(catCE/hipoE))*180/3.14159265359;
            }
            enemyMove(sf::Vector2f(catC/hipo, catO/hipo),rot);

            axisX = 0;
            axisY = 0;

            if(getEnemyActualSituation()->getPositionX()-getEnemyPreviousSituation()->getPositionX() > 0) axisX = 1;
            if(getEnemyActualSituation()->getPositionX()-getEnemyPreviousSituation()->getPositionX() < 0) axisX = -1;
            if(getEnemyActualSituation()->getPositionY()-getEnemyPreviousSituation()->getPositionY() > 0) axisY = 1;
            if(getEnemyActualSituation()->getPositionY()-getEnemyPreviousSituation()->getPositionY() < 0) axisY = -1;

            mapCollisions(map, axisX, axisY);
        }
        else
        {
            _state = 0;
            setEnemyActualSituation(getEnemyActualSituation()->getPosition(), int(getEnemyActualSituation()->getAngle())/5*5);
            _actualStep = 0;
            _loopClock->clockRestart();
            
            if(_astar != NULL)
            {
                delete _astar;
                _astar = NULL;
            }
        }
    
}
