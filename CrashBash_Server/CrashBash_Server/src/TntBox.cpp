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
    return this->deadOrAlive;
}


int TntBox::getXPos()
{
    return this->xPos;
}

int TntBox::getYPos()
{
    return this->yPos;
}
