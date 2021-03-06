/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: newman
 * 
 * Created on 10 de abril de 2018, 17:47
 */
#include "Sprite.h"

Sprite::Sprite(){
    
    _box = new sf::IntRect[1];
    _clock = new Clock();
    _bitmasks = new Bitmasks();//<====Boop
    _animationFrame = -1;
    _animationFrame=-1;
    _animation = false;
    _animationTime = -1;
    _animationNumFrames = -1;
}

Sprite::Sprite(Texture* texture, sf::IntRect box)
{
    _sprite.setTexture(*texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(0, 0);
    _sprite.setOrigin(0, 0);
    
   
    _box = new sf::IntRect[1];
    _box[0] = box;
    
    _animationFrame=-1;
    _animation = false;
    _animationTime = -1;
    _animationNumFrames = -1;
    
    _clock = new Clock();
    _bitmasks = new Bitmasks();//<== Booop
}

Sprite::Sprite(Texture* texture, sf::IntRect* box, int aniFrames, float aniTime){
    
    _sprite.setTexture(*texture->getTextureTexture());
    _sprite.setTextureRect(box[0]);
    _sprite.setPosition(0, 0);
    _sprite.setOrigin(0, 0);    
    
    _box = new sf::IntRect[aniFrames];
    
    for(int x=0 ; x<aniFrames; x++)
    {
        _box[x] = box[x];
    }
    
    if(aniTime<0){
        aniTime=0.1;
    }
    
    _animationNumFrames=aniFrames;
    _animationFrame=0;
    _animation = true;
    _animationTime = aniTime;
    
    _clock = new Clock();
    _bitmasks = new Bitmasks();
    
    
    delete box;
    box=NULL;
}

Sprite::Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position)
{
    _sprite.setTexture(*texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    
    _box = new sf::IntRect[1];
    _box[0] = box;
    
    _animationFrame=-1;
    _animation = false;
    _animationTime = -1;
    _animationNumFrames = -1;
    
    _clock = new Clock();
    _bitmasks = new Bitmasks();
}

Sprite::Sprite(Texture* texture, sf::IntRect box, sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale)
{
    _sprite.setTexture(*texture->getTextureTexture());
    _sprite.setTextureRect(box);
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setScale(scale);
    
    _animationFrame=-1;
    _animation = false;
    _animationTime = -1;
    _animationNumFrames = -1;
    
    _box = new sf::IntRect[1];
    _box[0] = box;
    
    _clock = new Clock();
    _bitmasks = new Bitmasks();
    

}


Sprite::Sprite(Texture* texture, sf::IntRect* box,  sf::Vector2f origin, sf::Vector2f position,  int aniFrames, float aniTime)
{
    //crear una animacion
    _sprite.setTexture(*texture->getTextureTexture());
    //setTectureRect
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setTextureRect(box[0]);
    
    _box = new sf::IntRect[aniFrames];
    
    for(int x=0 ; x<aniFrames; x++)
    {
        _box[x] = box[x];
    }
    
    if(aniTime<0){
        aniTime=0.1;
    }
    
    _animationNumFrames=aniFrames;
    _animationFrame=0;
    _animation = true;
    _animationTime = aniTime;
    
    _clock = new Clock();
    _bitmasks = new Bitmasks();
    
    
    delete box;
    box=NULL;
}


Sprite::Sprite(Texture* texture, sf::IntRect* box,  sf::Vector2f origin, sf::Vector2f position, sf::Vector2f scale,int aniFrames, float aniTime)
{
    //crear una animacion
    _sprite.setTexture(*texture->getTextureTexture());
    //setTectureRect
    _sprite.setPosition(position);
    _sprite.setOrigin(origin);
    _sprite.setScale(scale);
    _sprite.setTextureRect(box[0]);
    
    _box = new sf::IntRect[aniFrames];
    
    for(int x=0 ; x<aniFrames; x++)
    {
        _box[x] = box[x];
    }
    
    if(aniTime<0){
        aniTime=0.1;
    }
    
    _animationNumFrames=aniFrames;
    _animationFrame=0;
    _animation = true;
    _animationTime = aniTime;
    
    _clock = new Clock();
    _bitmasks = new Bitmasks();
    
    delete box;
    box=NULL;
    
}

Sprite::Sprite(const Sprite& orig)
{
    
}

Sprite::~Sprite()
{
    delete _box;
    _box=NULL;
    delete _clock;
    _clock=NULL;
    delete _bitmasks;
    _bitmasks=NULL;
}
   

bool Sprite::spriteIntersectsBounds(sf::Sprite spr){
    _sprite.getGlobalBounds().intersects(spr.getGlobalBounds());
}


bool Sprite::spriteIntersectsBounds(Sprite* spr){
    return spriteIntersectsBounds(spr->getSpriteSprite());
}

/*
bool Sprite::spriteIntersectsBounds(Sprite* spr)
{    
    cout <<"¿Intersecta? Primero:" <<endl;
    cout<< "   " << _box->top << "   " <<endl;
    cout<<_box->left<<"   "<<(_box->left + _box->width)<<endl;
    cout<<"   "<<(_box->top+_box->height)<<"   "<<endl;
    
    cout <<"¿Intersecta? Segundo:" <<endl;
    cout<< "   " << spr->getBox()->top << "   " <<endl;
    cout<< spr->getBox()->left <<"   "<<(spr->getBox()->left + spr->getBox()->width)<<endl;
    cout<<"   "<<(spr->getBox()->top+spr->getBox()->height)<<"   "<<endl;

    
    if(_box->intersects(*spr->getBox()) ){
        cout<<"SI QUE INTERSECTA"<<endl;
        return true;
    }
    else{
        return false;
    }
}*/


bool Sprite::spriteIntersectsPixel(const sf::Sprite& Object2, sf::Uint8 AlphaLimit) {
        sf::FloatRect Intersection;
        if (_sprite.getGlobalBounds().intersects(Object2.getGlobalBounds(), Intersection)) {
            sf::IntRect O1SubRect = _sprite.getTextureRect();
            sf::IntRect O2SubRect = Object2.getTextureRect();
            
            sf::Uint8* mask1 = _bitmasks->GetMask(_sprite.getTexture());
            sf::Uint8* mask2 = _bitmasks->GetMask(Object2.getTexture());
            
            // Loop through our pixels
            for (int i = Intersection.left; i < Intersection.left+Intersection.width; i++) {
                for (int j = Intersection.top; j < Intersection.top+Intersection.height; j++) {
                    
                    sf::Vector2f o1v = _sprite.getInverseTransform().transformPoint(i, j);
                    sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(i, j);
                    
                    // Make sure pixels fall within the sprite's subrect
                    if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
                        o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
                        o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {
                        
                        if (_bitmasks->GetPixel(mask1, _sprite.getTexture(), (int)(o1v.x)+O1SubRect.left, (int)(o1v.y)+O1SubRect.top) > AlphaLimit &&
                            _bitmasks->GetPixel(mask2, Object2.getTexture(), (int)(o2v.x)+O2SubRect.left, (int)(o2v.y)+O2SubRect.top) > AlphaLimit)
                            return true;
                        
                    }
                }
            }
        }
        return false;
}

void Sprite::spriteMove(sf::Vector2f move)
{
    _sprite.move(move);
}

void Sprite::spriteRotate(float rot)
{
    _sprite.rotate(rot);
}

void Sprite::spriteScale(sf::Vector2f scale)
{
    _sprite.scale(scale);
}
    
void Sprite::setSpritePosition(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

void Sprite::setSpriteOrigin(sf::Vector2f orig)
{
    _sprite.setOrigin(orig);
}

void Sprite::setSpriteScale(sf::Vector2f scale)
{
    _sprite.setScale(scale);
}

void Sprite::setSpriteRotation(float rot)
{
    _sprite.setRotation(rot);
}

void Sprite::setSpriteColor(int r, int g, int b, int a)
{
    
    
    //_sprite.setColor(sf::Color(sf::Uint8(r),sf::Uint8(g),sf::Uint8(b),sf::Uint8(a)));
    _sprite.setColor(sf::Color(r,g,b,a));
}

void Sprite::setSpriteTexture(Texture* texture)
{
    _sprite.setTexture(*texture->getTextureTexture());
}

void Sprite::setSpriteTextureRect(sf::IntRect box)
{
    _sprite.setTextureRect(box);
    _box[0].height = box.height;
    _box[0].width = box.width;
    _box[0].left = box.left;
    _box[0].top = box.top;
}
    

void Sprite::updateAnimation()
{
    //cout <<_clock->getClockAsSeconds()<<endl;

    if(_animation&&_clock->getClockAsSeconds()>=_animationTime)
    {
        //cout<<_animationFrame<<endl;
        if(_animationFrame>=_animationNumFrames) _animationFrame=0;
        _sprite.setTextureRect(_box[_animationFrame]);
        _animationFrame++;
        _clock->clockRestart();
    }
    
}

void Sprite::changeAnimation(sf::IntRect* box, int animationNumFrames, float animationTime){
    
    if(_animation){
    delete _box;
    _box=NULL;
    _animationNumFrames=animationNumFrames;
    _animationTime=animationTime;
    
    _box = new sf::IntRect[animationNumFrames];
    
    for(int x=0 ; x<animationNumFrames; x++)
    {
        _box[x] = box[x];
    }
    
    if(animationNumFrames<0){
        animationNumFrames=0.1;
    }
    
    _clock->clockRestart();
    
    _animationFrame=0;
    }
    
    delete box;
    box=NULL;
}

void Sprite::setAnimationFrame(int f)
{
    _animationFrame=f;
}
void Sprite::setAnimationNumFrames(int n)
{
    _animationNumFrames=n;
}

void Sprite::setAnimationTime(float t)
{
    //cout <<"CAMBIO ANIMATION TIME"<<endl;
    _animationTime=t;
}

sf::Vector2f Sprite::getSpritePosition()
{
    return _sprite.getPosition();
}

sf::Vector2f Sprite::getSpriteOrigin()
{
    return _sprite.getOrigin();
}

sf::Vector2f Sprite::getSpriteScale()
{
    return _sprite.getScale();
}

float Sprite::getSpriteRotation()
{
    return _sprite.getRotation();
}

sf::Sprite Sprite::getSpriteSprite()
{
    return _sprite;
}

sf::IntRect Sprite::getSpriteTextureRect()
{
    //hay que devolver el cuadrado de recorte actual
    if(_animation==true){
        //devolver el cuadrado de recorte del frame actual de la caja.
        return _box[_animationFrame];
    }
    else
    {
    return _box[0];
    }
}

sf::Texture Sprite::getSpriteTexture(){
    return *_sprite.getTexture();
}
sf::FloatRect Sprite::getGlobalBounds(){
    return _sprite.getGlobalBounds();
}

sf::Transform  Sprite::getSpriteInverseTransform(){
    
    return _sprite.getInverseTransform();
}

sf::IntRect* Sprite::getBox(){
    return _box;
}

int Sprite::getAnimationFrame(){
    return _animationFrame;
}
