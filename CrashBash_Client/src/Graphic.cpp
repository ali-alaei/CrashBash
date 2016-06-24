#include "Graphic.h"

Graphic::Graphic()
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
    return surface->show();
}

sf::Sprite Graphic::showNormalBoxes()
{
    return normalbox->show();
}

sf::Sprite Graphic::showTntBoxes()
{
    return tntbox->show();
}

sf::Sprite Graphic::showGiftBoxe()
{
    return giftbox->show();
}

sf::Sprite Graphic::showPlayers()
{
   /// return player->
}

sf::Sprite Graphic::showPlayersHealth()
{
   /// return player->
}
