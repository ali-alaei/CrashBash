#include "TntBox.h"
#include <iostream>
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
    //std::cout<<"\ninX: "<<xPos<<"\ninY"<<yPos<<endl;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize, textureSize));
    sprite.setPosition(xPos,yPos);
    return sprite;
    ///Sadegh will complete this part.
}
void TntBox::setXPos(int x)
{

    this->xPos = x;
}
void TntBox::setYPos(int y)
{

    this->yPos = y;
}
