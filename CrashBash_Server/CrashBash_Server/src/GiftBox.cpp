#include "../include/GiftBox.h"

GiftBox::GiftBox(int x,int y):Box(x,y)
{
    giftTypeNum=rand()%4;

    //ctor
}

int GiftBox::giftType()
{
    return this->giftTypeNum;
    ///ali to bayad ino begiri bad if bezani k befahmi b oon player chio ezafe koni
}


bool GiftBox::getDeadOrAlive()
{
    return this->deadOrAlive;
}

int GiftBox::getXPos()
{
    return this->xPos;
}

int GiftBox::getYPos()
{
    return this->yPos;
}
