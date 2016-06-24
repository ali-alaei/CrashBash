#include "TntBox.h"

TntBox::TntBox()
{
    texture.loadFromFile("TntBox.jpg");
    //ctor
}

TntBox::~TntBox()
{
    //dtor
}
sf::Sprite TntBox::show()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize, textureSize));
    sprite.setPosition(xPos,yPos);
    return sprite;
    ///Sadegh will complete this part.
}
