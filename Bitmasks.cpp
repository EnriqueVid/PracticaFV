/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 */

// Este metodo/clase utiliza fragmentos del codigo original de Nick Koirala (LittleMonkey LTD)
// * Autor de la version original: Nick Koirala (original version), ahnonay (SFML2 compatibility)
// * Collision Detection and handling class (c) 2009 - LittleMonkey Ltd

/* 
 * File:   Bitmasks.cpp
 * Author: carlos
 * 
 * Created on 21 de abril de 2018, 20:05
 */

#include "Bitmasks.h"
#include <SFML/Graphics.hpp>
#include <map>

Bitmasks::Bitmasks() {
    
}

sf::Uint8 Bitmasks::GetPixel (const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y)
{
    if (x>tex->getSize().x||y>tex->getSize().y)return 0;
            
    return mask[x+y*tex->getSize().x];   
}
sf::Uint8* Bitmasks::GetMask (const sf::Texture* tex)
{
    sf::Uint8* mask;
        std::map<const sf::Texture*, sf::Uint8*>::iterator pair = BitmasksMap.find(tex);
        if (pair==BitmasksMap.end())
        {
            sf::Image img = tex->copyToImage();
            mask = CreateMask (tex, img);
        }
        else
            mask = pair->second;
            
    return mask;
}
sf::Uint8* Bitmasks::CreateMask (const sf::Texture* tex, const sf::Image& img)
{
    sf::Uint8* mask = new sf::Uint8[tex->getSize().y*tex->getSize().x];
            
    for (unsigned int y = 0; y<tex->getSize().y; y++)
    {
        for (unsigned int x = 0; x<tex->getSize().x; x++)
            mask[x+y*tex->getSize().x] = img.getPixel(x,y).a;
    }
            
    BitmasksMap.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex,mask));
            
    return mask;    
}

Bitmasks::Bitmasks(const Bitmasks& orig) {
    
}

Bitmasks::~Bitmasks() {
    std::map<const sf::Texture*, sf::Uint8*>::const_iterator end = BitmasksMap.end();
    for (std::map<const sf::Texture*, sf::Uint8*>::const_iterator iter = BitmasksMap.begin(); iter!=end; iter++)
        delete [] iter->second;    
}

