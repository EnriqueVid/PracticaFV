#ifndef MESSAGE_H
#define MESSAGE_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>


#include "Font.h"
#include "Text.h"
#include "Sprite.h"
#include "Texture.h"


class Message {
public:
    Message(int number, std::string file, Texture* texturebg);
    virtual ~Message();

private:
    
    Text* _text;
    Font* _font;
    Texture* _tbox;
    Sprite* _sbox;
};


#endif /* MESSAGE_H */
