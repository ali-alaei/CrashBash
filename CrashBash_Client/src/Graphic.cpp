#include "Graphic.h"
#include "iostream"
Graphic::Graphic():width(1300),height(973), surface(width,height)
{
window=new sf::RenderWindow(sf::VideoMode(width, height), "CrashBash");
}

Graphic::~Graphic()
{
}

void Graphic::showSurface()
{
    window->draw(surface.show());
}

void Graphic::showNormalBoxes(NormalBox* normalBoxObj)
{
    this->normalbox=normalBoxObj;
    window->draw(normalbox->show());
}

void Graphic::showTntBoxes(TntBox* tntBoxObj)
{
    this->tntbox=tntBoxObj;
    window->draw(tntbox->show());
}

void Graphic::showGiftBoxes(GiftBox* giftBoxObj)
{
    this->giftbox=giftBoxObj;
    window->draw(giftbox->show());
}

void Graphic::showPlayers(Player* playerObj)
{
    this->player=playerObj;
    window->draw(player->show());
}

void Graphic::showPlayersHealthFull(Player* playerObj,int x,int y)
{
    this->player=playerObj;
    window->draw(player->showPlayerHealthFull(x,y));
}

void Graphic::showPlayerIcon(Player* playerObj,int x,int y)
{
    this->player=playerObj;
    window->draw(player->showPlayerIcon(x,y));
}


void Graphic::showPlayersHealthEmpty(Player* playerObj,int x,int y)
{
    this->player=playerObj;
    window->draw(player->showPlayerHealthEmpty(x,y));
}

sf::RenderWindow* Graphic::getWindow()
{
    return window;
}
