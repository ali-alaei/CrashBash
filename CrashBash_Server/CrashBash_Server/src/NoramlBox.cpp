#include "NoramlBox.h"

NoramlBox::NoramlBox(int x,int y):Box(x,y),speed(0),owner(0),
isThrow(0),rate(0)
{

}

NoramlBox::~NoramlBox()
{

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
    for(int i=0;i</*tedad playe*/;i++)
    {
        for(int j= -50;j<50;j++)
            for(int h= -50;h<50;h++)
                if(this->xPos+j ==playervector[i].xPos+h && this->yPos+j ==playervector[i].yPos+h)
                   {
                       player=playervector[i];
                       return true;
                   }
    }
}


bool NoramlBox::checkCollision()
{
    if(rate==0)
        return true;

    for(int i=0;i</*tedad playe*/;i++)
    {
        for(int j= -50;j<50;j++)
            for(int h= -50;h<50;h++)

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


