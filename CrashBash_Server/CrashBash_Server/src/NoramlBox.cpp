#include "NoramlBox.h"

NoramlBox::NoramlBox(int x,int y):Box(x,y),speed(0),owner(0),
isThrow(0),rate(0)
{
    //ctor
}

NoramlBox::~NoramlBox()
{
    //dtor
}

bool NoramlBox::checkCollisiontToPlayer()
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

bool NoramlBox::updateBox()
{


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
    if(direction==0)
    {
        yPos-=speed;
        rate-=speed;
    }

    else if(direction==1)
    {
        xPos+=speed;
        rate-=speed;
    }

    else if(direction==2)
    {
        yPos+=speed;
        rate-=speed;
    }

    else if(direction==3)
    {
        xPos-=speed;
        rate-=speed;
    }
}

void NoramlBox::setIsThrow(bool a)
{
    this->isThrow=a;
}
