#include "NoramlBox.h"

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
    for(int i=0;i<playersNum;i++)
    {
        if(this->xPos>playerVector[i]->getXPos() && this->xPos<playerVector[i]->getXPos()+boxSize
            && this->yPos>playerVector[i]->getYPos() && this->yPos<playerVector[i]->getYPos()+boxSize)
        {
            this->player=playerVector[i];
            return true;
        }

        if(this->xPos>playerVector[i]->getXPos() && this->xPos<playerVector[i]->getXPos()+boxSize
            && this->yPos+playerSize>playerVector[i]->getYPos() && this->yPos+playerSize<playerVector[i]->getYPos()+boxSize)
        {
            this->player=playerVector[i];
            return true;
        }

        if(this->xPos+playerSize>playerVector[i]->getXPos() && this->xPos+playerSize<playerVector[i]->getXPos()+boxSize
            && this->yPos>playerVector[i]->getYPos() && this->yPos<playerVector[i]->getYPos()+boxSize)
        {
            this->player=playerVector[i];
            return true;
        }

        if(this->xPos+playerSize>playerVector[i]->getXPos() && this->xPos+playerSize<playerVector[i]->getXPos()+boxSize
            && this->yPos+playerSize>playerVector[i]->getYPos() && this->yPos+playerSize<playerVector[i]->getYPos()+boxSize)
        {
            this->player=playerVector[i];
            return true;
        }
    }

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
    this->direction=a;
}

void NoramlBox::setRate(int a)
{
    this->rate=a;
}

void NoramlBox::moveCatchBox()
{
    if(this->owner==1)
    {
        if(direction==1)
        {
            yPos-=speed;
            rate-=speed;
        }

        else if(direction==2)
        {
            xPos+=speed;
            rate-=speed;
        }

        else if(direction==3)
        {
            yPos+=speed;
            rate-=speed;
        }

        else if(direction==4)
        {
            xPos-=speed;
            rate-=speed;
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

void NoramlBox::move()
