#include "Surface.h"

Surface::Surface(int w,int h):width(w),height(h)
{
    ///do khate paiin pak mishe chon gharare az file bekhooni,m
    ///ama age size dge az file bekhoonim zamin be ham mikhore

    texture.loadFromFile("Stage.jpg");
}

Surface::~Surface()
{
    //dtor
}


sf::Sprite Surface::show()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, width,height));
    return sprite;
}
