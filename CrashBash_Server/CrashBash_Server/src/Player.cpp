#include "../include/Player.h"

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
        if(this->space==1)
        {
            for(int i=0;i<normalBoxesNum;i++)
            {
                if(this->xPos>normalBoxes[i]->getXPos() && this->xPos<normalBoxes[i]->getXPos()+boxSize
                    && this->yPos>normalBoxes[i]->getYPos() && this->yPos<normalBoxes[i]->getYPos()+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }

                if(this->xPos>normalBoxes[i]->getXPos() && this->xPos<normalBoxes[i]->getXPos()+boxSize
                    && this->yPos+playerSize>normalBoxes[i]->getYPos() && this->yPos+playerSize<normalBoxes[i]->getYPos()+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }

                if(this->xPos+playerSize>normalBoxes[i]->getXPos() && this->xPos+playerSize<normalBoxes[i]->getXPos()+boxSize
                    && this->yPos>normalBoxes[i]->getYPos() && this->yPos<normalBoxes[i]->getYPos()+boxSize)
                {
                    this->tokenBox=normalBoxes[i];
                    return true;
                }

                if(this->xPos+playerSize>normalBoxes[i]->getXPos() && this->xPos+playerSize<normalBoxes[i]->getXPos()+boxSize
                    && this->yPos+playerSize>normalBoxes[i]->getYPos() && this->yPos+playerSize<normalBoxes[i]->getYPos()+boxSize)
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
    this->yPos+=speed;
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
        if(this->space==1)
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

//void Player::setInputData(Input input)
//{
//    this->inputData=&input;
//}

//void Player::setTokenBox(NoramlBox normalbox)
//{
 //   this->tokenBox=&normalbox;
//}

void Player::setGiftBoxVector(std::vector <GiftBox> &gifts)
{
    for(int i=0;i<giftBoxesNum;i++)
    {
        giftBoxes.push_back(&gifts[i]);
    }
}

void Player::setTntBoxVector(std::vector <TntBox> &tnts)
{
    for(int i=0;i<tntBoxesNum;i++)
    {
        tntBoxes.push_back(&tnts[i]);
    }
}

void Player::setNoramlBoxVector(std::vector <NoramlBox> &normals)
{
    for(int i=0;i<normalBoxesNum;i++)
    {
        normalBoxes.push_back(&normals[i]);
    }
}

bool Player::playerCollisionGiftBox()
{
    for(int i=0;i<giftBoxesNum;i++)
    {
        if(this->xPos>giftBoxes[i]->getXPos() && this->xPos<giftBoxes[i]->getXPos()+boxSize
            && this->yPos>giftBoxes[i]->getYPos() && this->yPos<giftBoxes[i]->getYPos()+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }

        if(this->xPos>giftBoxes[i]->getXPos() && this->xPos<giftBoxes[i]->getXPos()+boxSize
            && this->yPos+playerSize>giftBoxes[i]->getYPos() && this->yPos+playerSize<giftBoxes[i]->getYPos()+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>giftBoxes[i]->getXPos() && this->xPos+playerSize<giftBoxes[i]->getXPos()+boxSize
            && this->yPos>giftBoxes[i]->getYPos() && this->yPos<giftBoxes[i]->getYPos()+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>giftBoxes[i]->getXPos() && this->xPos+playerSize<giftBoxes[i]->getXPos()+boxSize
            && this->yPos+playerSize>giftBoxes[i]->getYPos() && this->yPos+playerSize<giftBoxes[i]->getYPos()+boxSize)
        {
            this->earnedBox=giftBoxes[i];
            return true;
        }
    }

    return false;
}


bool Player::playerCollisionTntBox()
{
    for(int i=0;i<tntBoxesNum;i++)
    {
        if(this->xPos>tntBoxes[i]->getXPos() && this->xPos<tntBoxes[i]->getXPos()+boxSize
            && this->yPos>tntBoxes[i]->getYPos() && this->yPos<tntBoxes[i]->getYPos()+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }

        if(this->xPos>tntBoxes[i]->getXPos() && this->xPos<tntBoxes[i]->getXPos()+boxSize
            && this->yPos+playerSize>tntBoxes[i]->getYPos() && this->yPos+playerSize<tntBoxes[i]->getYPos()+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>tntBoxes[i]->getXPos() && this->xPos+playerSize<tntBoxes[i]->getXPos()+boxSize
            && this->yPos>tntBoxes[i]->getYPos() && this->yPos<tntBoxes[i]->getYPos()+boxSize)
        {
            this->collisionBox=tntBoxes[i];
            return true;
        }

        if(this->xPos+playerSize>tntBoxes[i]->getXPos() && this->xPos+playerSize<tntBoxes[i]->getXPos()+boxSize
            && this->yPos+playerSize>tntBoxes[i]->getYPos() && this->yPos+playerSize<tntBoxes[i]->getYPos()+boxSize)
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

int Player::getXPos()
{
    return this->xPos;
}

int Player::getYPos()
{
    return this->yPos;
}

int Player::getPlayerHealth()
{
    return this->health;
}


bool Player::checkCollisionToBox()
{
    if(direction==1)
    {
        for(int i=0;i<normalBoxesNum;i++)
        {
            if(this->xPos>normalBoxes[i]->getXPos() && this->xPos<normalBoxes[i]->getXPos()+boxSize
                && this->yPos-5>normalBoxes[i]->getYPos() && this->yPos-5<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }


            if(this->xPos+playerSize>normalBoxes[i]->getXPos() && this->xPos+playerSize<normalBoxes[i]->getXPos()+boxSize
                && this->yPos-5>normalBoxes[i]->getYPos() && this->yPos-5<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }
        }
        return true;
    }
    else if(direction==2)
    {
        for(int i=0;i<normalBoxesNum;i++)
        {
            if(this->xPos+5>normalBoxes[i]->getXPos() && this->xPos+5<normalBoxes[i]->getXPos()+boxSize
                && this->yPos>normalBoxes[i]->getYPos() && this->yPos<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }


            if(this->xPos+5>normalBoxes[i]->getXPos() && this->xPos+5<normalBoxes[i]->getXPos()+boxSize
                && this->yPos+playerSize>normalBoxes[i]->getYPos() && this->yPos+playerSize<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }
        }
        return true;

    }
    else if(direction==3)
    {
        for(int i=0;i<normalBoxesNum;i++)
        {
            if(this->xPos>normalBoxes[i]->getXPos() && this->xPos<normalBoxes[i]->getXPos()+boxSize
                && this->yPos+5>normalBoxes[i]->getYPos() && this->yPos+5<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }

            if(this->xPos+playerSize>normalBoxes[i]->getXPos() && this->xPos+playerSize<normalBoxes[i]->getXPos()+boxSize
                && this->yPos+5>normalBoxes[i]->getYPos() && this->yPos+5<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }
        }
        return true;

    }

    else if(direction==4)
    {

        for(int i=0;i<normalBoxesNum;i++)
        {
            if(this->xPos-5>normalBoxes[i]->getXPos() && this->xPos-5<normalBoxes[i]->getXPos()+boxSize
                && this->yPos>normalBoxes[i]->getYPos() && this->yPos<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }


            if(this->xPos-5>normalBoxes[i]->getXPos() && this->xPos-5<normalBoxes[i]->getXPos()+boxSize
                && this->yPos+playerSize>normalBoxes[i]->getYPos() && this->yPos+playerSize<normalBoxes[i]->getYPos()+boxSize)
            {
                return false;
            }
        }
        return true;
    }

}

int Player::getDirection()
{
    return this->direction;
}

int Player::getId()
{
    return this->id;
}
void Player::setGiftBoxesNum(int giftBoxes)
{
    this->giftBoxesNum = giftBoxes;

}
void Player::setTntBoxesNum(int tntBoxes)
{
    this->tntBoxesNum = tntBoxes;

}

void Player::setSpace(bool a)
{
    this->space=a;
}

void Player::setId(int a)
{

    this->id = a;
}
