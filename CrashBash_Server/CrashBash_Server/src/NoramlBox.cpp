#include "../include/NoramlBox.h"
#include <iostream>
NoramlBox::NoramlBox(int x,int y):Box(x,y),speed(0),owner(0),
isThrow(0),rate(0)
{

}

NoramlBox::~NoramlBox()
{

}

bool NoramlBox::checkCollisionToWallOrRate()
{

    if(rate==0)
        return true;

    if(this->xPos<80 || this->xPos>1160
        ||this->yPos>833 || this->yPos<80)
    {
        return true;
    }

    if(this->xPos + boxSize <80 || this->xPos + boxSize >1160
        ||this->yPos>833 || this->yPos<80)
    {
        return true;
    }

    if(this->xPos<80 || this->xPos>1160
        ||this->yPos + boxSize>833 || this->yPos + boxSize<80)
    {
        return true;
    }

    if(this->xPos + boxSize<80 || this->xPos + boxSize>1160
        ||this->yPos + boxSize>833 || this->yPos + boxSize<80)
    {
        return true;
    }

}


bool NoramlBox::checkCollision()
{
    for(int i=0;i<2;i++)
    {
        if(yPos<=playerVector[i].getYPos()+60 && yPos>playerVector[i].getYPos())
            if(xPos<=playerVector[i].getXPos()+60 && xPos>playerVector[i].getXPos()-60)
            {
                    return true;
            }
    }
    return false;
}
bool NoramlBox::hasOwner()
{

    return this->owner;

}
void NoramlBox::setOwner(bool a)
{
    this->owner=a;
}

void NoramlBox::setDirection(int a)
{
    this->direction=a;
}

void NoramlBox::setSpeed(int a)
{
    this->speed=a;
}

void NoramlBox::setRate(int a)
{
    this->rate=a;
}

void NoramlBox::moveCatchBox()
{
    if(this->owner==1)
    {
        if(player->getisKeyPressed())
        {
            if(direction==1)
            {
                xPos=player->getXPos();
                yPos=player->getYPos()-60;
            }

            else if(direction==2)
            {
                xPos=player->getXPos()+60;
                yPos=player->getYPos();
            }

            else if(direction==3)
            {
                xPos=player->getXPos();
                yPos=player->getYPos()+60;
            }

            else if(direction==4)
            {
                xPos=player->getXPos()-60;
                yPos=player->getYPos();
            }
        }
    }
}

void NoramlBox::setIsThrow(bool a)
{
    this->isThrow=a;
}

bool NoramlBox::getDeadOrAlive()
{
    return this->deadOrAlive;
}

void NoramlBox::setPlayersNum(int a)
{
    this->playersNum=a;
}


int NoramlBox::getXPos()
{
    return this->xPos;
}

int NoramlBox::getYPos()
{
    return this->yPos;
}

int NoramlBox::getRate()
{
    return rate;
}

bool NoramlBox::getIsThrow()
{


    return this->isThrow;
}

void NoramlBox::setPlayerVector(std::vector <Player> &players)
{
    playerVector = players;
}

void NoramlBox::moveCatchBoxThrow()
{
    if(this->owner==1)
    {
        if(player->getisKeyPressed())
        {
            if(direction==1)
            {
                yPos-=speed/2;
                rate-=speed;
            }

            else if(direction==2)
            {
                xPos+=speed/2;
                rate-=speed;
            }

            else if(direction==3)
            {
                yPos+=speed/2;
                rate-=speed;
             }

            else if(direction==4)
            {
                xPos-=speed/2;
                rate-=speed;
            }
        }
    }
}
void NoramlBox::setDeadOrAlive(bool a)
{
    this->deadOrAlive=a;
}
