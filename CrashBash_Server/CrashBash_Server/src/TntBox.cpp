#include "../include/TntBox.h"

TntBox::TntBox(int x,int y):Box(x,y)
{
    //ctor
}

TntBox::~TntBox()
{
    //dtor
}

bool TntBox::getDeadOrAlive()
{
    if(this->deadOrAlive==true)
        return true;
    else
        return false;
}


int TntBox::getXPos()
{
    return this->xPos;
}

int TntBox::getYPos()
{
    return this->yPos;
}
