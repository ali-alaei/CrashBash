#include "Box.h"

Box::Box(int x,int y):xPos(x),yPos(y),deadOrAlive(1)
{
    //ctor
}

Box::~Box()
{
    //dtor
}

bool NoramlBox::checkCollisiontToPlayer()
{
    for(int i=0;i</*tedad playe*/;i++)
    {

        if(this->xPos>playervector[i].xPos && this->xPos<playervector[i].xPos+playerSize
            && this->yPos>playervector[i].yPos && this->yPos<playervector[i].yPos+playerSize)
        {
            this->player=playervector[i];
            return true;
        }

        if(this->xPos>playervector[i].xPos && this->xPos<playervector[i].xPos+playerSize
            && this->yPos+boxSize>playervector[i].yPos && this->yPos+boxSize<playervector[i].yPos+playerSize)
        {
            this->player=playervector[i];
            return true;
        }

        if(this->xPos+boxSize>playervector[i].xPos && this->xPos+boxSize<playervector[i].xPos+playerSize
            && this->yPos>playervector[i].yPos && this->yPos<playervector[i].yPos+playerSize)
        {
            this->player=playervector[i];
            return true;
        }

        if(this->xPos+boxSize>playervector[i].xPos && this->xPos+boxSize<playervector[i].xPos+playerSize
            && this->yPos+boxSize>playervector[i].yPos && this->yPos+boxSize<playervector[i].yPos+playerSize)
        {
            this->player=playervector[i];
            return true;
        }

    }
}
