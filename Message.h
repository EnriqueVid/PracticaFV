#ifndef MESSAGE_H
#define MESSAGE_H

#include <SFML/Graphics.hpp>
#include "Text.h"
#include "Sprite.h"
#include "Texture.h"

class Message {
public:
    Message(int number, Font* font, Texture* texturebg, sf::FloatRect pjbounds, sf::Vector2f pjposition);
    Sprite* getSpriteMessage();
    Text* getTextMessage();
    Font* getFontMessage();
    virtual ~Message();

private:
    
    Text* _text;
    Sprite* _sbox;
};


#endif /* MESSAGE_H */
