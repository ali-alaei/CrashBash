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

bool Player::playerBox()
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
     }
}


void Player::increasePlayerHealth()
{
    this->health+=1;
}

void Player::decreasePlayerHealth()
{
    this->health-=1;
}

void Player::setNormalBoxesNum(int x)
{
    this->normalBoxesNum=x;
}

void Player::setDirection(int x)
{
    this->direction=x;
}

void Player::increaseSpeed()
{
    this->speed+=3;
}

void Player::increaseSpeedRate()
{
    this->throwSpeed+=3;
}

void Player::increaseThrowRate()
{
    this->throwRate+=3;
}

void Player::setInputData(Input input)
{
    this->inputData=input;
}

void Player::setTokenBox(NoramlBox normalbox)
{
    this->tokenBox=normalbox;
}

void Player::setGiftBoxVector(std::vector <GiftBox> &gifts)
{
    this->giftBoxes=giftbox;
}

void Player::setTntBoxVector(std::vector <TntBox> &tnts)
{
    this->tntBoxes=tntbox;
}

void Player::setNormalBoxVector(std::vector <NormalBox> &normals)
{
    this->normalBoxes=normalbox;
}

bool Player::playerCollisionGiftBox()
{
    for(int i=0;i<GiftBoxesNum;i++)
    {
        if(this->xPos>giftBoxes[i].xPos && this->xPos<giftBoxes[i].xPos+boxSize
            && this->yPos>giftBoxes[i].yPos && this->yPos<giftBoxes[i].yPos+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }

        if(this->xPos>giftBoxes[i].xPos && this->xPos<giftBoxes[i].xPos+boxSize
            && this->yPos+playerSize>giftBoxes[i].yPos && this->yPos+playerSize<giftBoxes[i].yPos+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>giftBoxes[i].xPos && this->xPos+playerSize<giftBoxes[i].xPos+boxSize
            && this->yPos>giftBoxes[i].yPos && this->yPos<giftBoxes[i].yPos+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>giftBoxes[i].xPos && this->xPos+playerSize<giftBoxes[i].xPos+boxSize
            && this->yPos+playerSize>giftBoxes[i].yPos && this->yPos+playerSize<giftBoxes[i].yPos+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }
    }

    return false;
}


bool Player::playerCollisionTntBox()
{
    for(int i=0;i<TntBoxesNum;i++)
    {
        if(this->xPos>tntBoxes[i].xPos && this->xPos<tntBoxes[i].xPos+boxSize
            && this->yPos>tntBoxes[i].yPos && this->yPos<tntBoxes[i].yPos+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }

        if(this->xPos>tntBoxes[i].xPos && this->xPos<tntBoxes[i].xPos+boxSize
            && this->yPos+playerSize>tntBoxes[i].yPos && this->yPos+playerSize<tntBoxes[i].yPos+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>tntBoxes[i].xPos && this->xPos+playerSize<tntBoxes[i].xPos+boxSize
            && this->yPos>tntBoxes[i].yPos && this->yPos<tntBoxes[i].yPos+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>tntBoxes[i].xPos && this->xPos+playerSize<tntBoxes[i].xPos+boxSize
            && this->yPos+playerSize>tntBoxes[i].yPos && this->yPos+playerSize<tntBoxes[i].yPos+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }
    }

    return false;
}
bool Player::OwnedBox()
{

    return this->ownBox;

}
