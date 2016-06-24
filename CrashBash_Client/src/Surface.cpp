#include "Surface.h"

Surface::Surface()
{
    ///do khate paiin pak mishe chon gharare az file bekhooni,m
    ///ama age size dge az file bekhoonim zamin be ham mikhore

    width=1200;
    height=897;
    window = sf::RenderWindow(sf::VideoMode(width, height), "CrashBash");
    texture.loadFromFile("Stage.jpg");
}

Surface::~Surface()
{
    //dtor
}

sf::RenderWindow Surface::renderWindowAccess()
{
    return window;
}

sf::Sprite Surface::show()
{
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, textureSize, textureSize));
    sprite.setPosition(xPos,yPos);
    return sprite;
}
