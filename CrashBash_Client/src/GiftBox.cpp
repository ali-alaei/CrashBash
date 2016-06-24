#include "GiftBox.h"

GiftBox::GiftBox()
{
    texture.loadFromFile("GiftBox.jpg");
    //ctor
}

GiftBox::~GiftBox()
{
    //dtor
}
sf::Sprite GiftBox::show()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize, textureSize));
    sprite.setPosition(xPos,yPos);
    return sprite;
    ///Sadegh will complete this part.

}
