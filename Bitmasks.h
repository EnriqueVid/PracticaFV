/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bitmasks.h
 * Author: carlos
 *
 * Created on 21 de abril de 2018, 20:05
 */

#ifndef BITMASKS_H
#define BITMASKS_H
#include <SFML/Graphics.hpp>
#include <map>

class Bitmasks {
public:
    Bitmasks();
    Bitmasks(const Bitmasks& orig);
    
    sf::Uint8 GetPixel (const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y);
    sf::Uint8* GetMask (const sf::Texture* tex);
    sf::Uint8* CreateMask (const sf::Texture* tex, const sf::Image& img);

    virtual ~Bitmasks();
    
    
    
private:
    std::map<const sf::Texture*, sf::Uint8*> BitmasksMap;

};

#endif /* BITMASKS_H */

