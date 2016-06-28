#include "Player.h"

Player::Player(int x,int y):xPos(x),yPos(y)
{
    this->throwSpeed=5;
    this->throwRate=100;
    this->health=3;
    this->direction=2;
    this->speed=7;
    this->ownBox=0;
    this->deadOrAlive=1;


}

Player::~Player()
{
    //dtor
}

void Player::playerBox()
{
    if(this->ownBox==0)
    {
        if(space==1)
        {
            for(int i=0;i<normalBoxesNum;i++)
            {
                if(this->xPos>normalBoxes[i].xPos && this->xPos<normalBoxes[i].xPos+boxSize
                    && this->yPos>normalBoxes[i].yPos && this->yPos<normalBoxes[i].yPos+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }

                if(this->xPos>normalBoxes[i].xPos && this->xPos<normalBoxes[i].xPos+boxSize
                    && this->yPos+playerSize>normalBoxes[i].yPos && this->yPos+playerSize<normalBoxes[i].yPos+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }

                if(this->xPos+playerSize>normalBoxes[i].xPos && this->xPos+playerSize<normalBoxes[i].xPos+boxSize
                    && this->yPos>normalBoxes[i].yPos && this->yPos<normalBoxes[i].yPos+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }

                if(this->xPos+playerSize>normalBoxes[i].xPos && this->xPos+playerSize<normalBoxes[i].xPos+boxSize
                    && this->yPos+playerSize>normalBoxes[i].yPos && this->yPos+playerSize<normalBoxes[i].yPos+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }
            }
        }
    }
    return false;
}

void Player::changePosUp()
{
    this->yPos-=speed;
}


void Player::changePosDown()
{
    this->yPos+=speed
}



void Player::changePosRight()
{
    this->xPos+=speed;
}


void Player::changePosLeft()
{
    this->xPos-=speed;
}


void Player::changePosUR()
{
    this->xPos+=speed;
    this->yPos-=speed;
}


void Player::changePosUL()
{
    this->xPos-=speed;
    this->yPos-=speed;
}


void Player::changePosDR()
{
    this->xPos+=speed;
    this->yPos+=speed;
}


void Player::changePosDL()
{
    this->xPos-=speed;
    this->yPos+=speed;
}

void Player::catchBox()
{
    ownBox=1;
    tokenBox->setOwner(1);
    tokenBox->setDirection(this->direction);
    tokenBox->setSpeed(this->speed);
}

void Player::throwBox()
{
    if(ownBox==1)
    {
        if(space==1)
        {
            tokenBox->setDirection(this->direction);
            tokenBox->setSpeed(this->throwSpeed);
            tokenBox->setRate(this->throwRate);
            tokenBox->setIsThrow(1);
            ownBox=0;
        }
        ///bayad is throw box ro ham true konim
    }
}

void Player::setSpaceKey(int space)
{
    this->space=space;
}

void Player::increasePlayerHealth()
{

///increase health one block
}

void Player::decreasePlayerHealth()
{

///decrease health one block
}

void Player::setNormalBoxesNum(int x)
{
    this->normalBoxesNum=x;
}

void Player::setDirection(int x)
{
    this->direction=x;
}

/*{
                for(int u=0;u<=playerSize;u+=playerSize)
                    for(int j=0;j<=playerSize;j++)
                        {
                            for(int h=0;h<=boxSize;h+=boxSize)
                                for(int y=0;y<=boxSize;y++)
                                    if(this->xPos+j==normalboxes[i].xPos+y && this->yPos+u==normalboxes[i].yPos+h)
                                    {
                                        this->box=normalboxes[i];
                                        break;
                                    }
              */
