#include "NormalBox.h"
#include <iostream>

NormalBox::NormalBox()
{
    texture.loadFromFile("NormalBox.jpg");
    //ctor
}

NormalBox::~NormalBox()
{
    //dtor
}
sf::Sprite NormalBox::show()
{
   // std::cout<<"\ninX: "<<xPos<<"\ninY"<<yPos<<endl;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize, textureSize));
    sprite.setPosition(xPos,yPos);
    return sprite;
    ///Sadegh will complete this part.
}
void NormalBox::setXPos(int x)
{

    this->xPos = x;
}
void NormalBox::setYPos(int y)
{


    this->yPos = y;
}
