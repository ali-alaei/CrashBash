#include "Graphic.h"

Graphic::Graphic():width(1300),height(973),window(sf::VideoMode(width, height), "CrashBash"), surface(width,height)
{
    ///meghdar dehie pointer ha

    //ctor
}

Graphic::~Graphic()
{
    //dtor
}

sf::Sprite Graphic::showSurface()
{
    window.draw(surface.show());
}

sf::Sprite Graphic::showNormalBoxes()
{
    window.draw(normalbox->show());
}

sf::Sprite Graphic::showTntBoxes()
{
    window.draw(tntbox->show());
}

sf::Sprite Graphic::showGiftBoxe()
{
    window.draw(giftbox->show());
}

sf::Sprite Graphic::showPlayers()
{
    window.draw(player->show());
}

sf::Sprite Graphic::showPlayersHealth()
{
   /// return player->
}
