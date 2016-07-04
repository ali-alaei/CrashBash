#include "../include/Controller.h"

Controller::Controller(): playerNumbers(2),normalBoxNumbers(8),giftBoxNumbers(3),tntBoxNumbers(5),parser(this->playerNumbers)
{



}
Controller::~Controller()
{

}
void Controller::createPlayers()
{
    players.push_back(Player(80,80));
    players.push_back(Player(1020,698));
}
void Controller::createNormalBoxes()
{

    int x[8];
    int y[8];
    for(int i = 0; i < this->normalBoxNumbers; i++)
    {
        x[i] = (rand() %  1081) + 80;
        y[i] = (rand() % 754) + 80;

    }
    for(int i = 0; i < this->normalBoxNumbers; i++)
    {
        normals.push_back(NoramlBox(x[i],y[i]));

    }


}
void Controller::createTntBoxes()
{

    int x[5];
    int y[5];
    for(int i = 0; i < this->tntBoxNumbers; i++)
    {
        x[i] = (rand() %  1081) + 80;
        y[i] = (rand() % 754) + 80;

    }


    for(int i = 0; i < this->tntBoxNumbers; i++)
    {
        tnts.push_back(TntBox(x[i],y[i]));

    }
}
void Controller::createGiftBoxes()
{

    int x[3];
    int y[3];
    for(int i = 0; i < this->giftBoxNumbers; i++)
    {
        x[i] = (rand() %  1081) + 80;
        y[i] = (rand() % 754) + 80;

    }


    for(int i = 0; i < this->giftBoxNumbers; i++)
    {
        gifts.push_back(GiftBox(x[i],y[i]));

    }

}

void Controller::run()
{
    createPlayers();
    createNormalBoxes();
    createTntBoxes();
    createGiftBoxes();
    setPlayersVectorToNormalBox();
    connection.start();
    connection2.start();

    while(true)
    {
        players[0].setisKeyPressed(0);
        players[1].setisKeyPressed(0);
        if(connection.haveInQ())
        {
            players[0].setisKeyPressed(1);
            sf::Packet packet = connection.receivePacket();
            string s;
            packet >>s;
            setWmodelToParser(s);
            parser.deCode(1);
        }
        else if(connection2.haveInQ())
        {
            players[1].setisKeyPressed(1);
            sf::Packet packet = connection2.receivePacket();
            string s;
            packet >>s;
            setWmodelToParser(s);
            parser.deCode(2);
        }
        setParserGiftBoxNum();
        setParserNormalBoxNum();
        setParserTntBoxNum();
        setParserGiftBoxVector();
        setParserNormalBoxVector();
        setParserTntBoxVector();
        setParserPlayerVector();
        setParserPlayerId();
        setPlayerNormalBoxesNum();
        setPlayerGiftBoxesNum();
        setPlayerTntBoxesNum();
        setPlayerDirection();
        setPlayerGiftBoxes();
        setPlayerTntBoxes();
        setPlayerNormalBoxes();
        setPlayerSpaceKey();
        checkPlayerCollisionToBox();///jadid zadam (az too box rad nashe)
        playerCollisionToWall();///jadid az divar rad nashe
        changePosition();
        playerCollisionToNormalBox();
        playerCollisionToTntBox();
        playerCollisionToGiftBox();
        whoIsWinner();
        parser.code();
        if(parser.ch)
        {
            sf::Packet packet;
            packet <<parser.getWmodel();
            connection.sendPacket(packet);
            connection2.sendPacket(packet);
        }
        for(int i=0;i<normals.size();i++)
        {
            std::cout<<"\n"<<normals[i].getXPos()<<"\n";
            std::cout<<normals[i].getYPos()<<"\n";
        }
        setZeroToInputs();
    }

}
void Controller::deleteNormalBox()
{
    for(int i=0; i < normals.size(); i++)
    {
         if(!normals[i].getDeadOrAlive())
        {
            normals.erase(normals.begin()+(i));
            this->normalBoxNumbers--;
        }
    }
}
void Controller::deleteGiftBox()
{
     for(int i=0; i < gifts.size(); i++)
     {
        if(gifts[i].getDeadOrAlive())
        {
            gifts.erase(gifts.begin()+(i-1));
            this->giftBoxNumbers--;
        }
     }
}
void Controller::deleteTntBox()
{
        for(int i=0; i < tnts.size(); i++)
        {
             if(!tnts[i].getDeadOrAlive())
            {
            tnts.erase(tnts.begin()+i);
            this->tntBoxNumbers--;

            }
        }
}
void Controller::changePosition()
{
    for(int i=0; i < playerNumbers; i++)
    {

        if(parser.input[i]->up)
        {
            players[i].changePosUp();
        }

        else if(parser.input[i]->down)
        {
            players[i].changePosDown();
        }
        else if(parser.input[i]->right)
        {
            players[i].changePosRight();
        }
        else if(parser.input[i]->left)
        {
            players[i].changePosLeft();
        }
        else if(parser.input[i]->right && parser.input[i]->up)
        {
            players[i].changePosUR();
        }
        else if(parser.input[i]->left && parser.input[i]->up)
        {
            players[i].changePosUL();
        }
        else if(parser.input[i]->left && parser.input[i]->down)
        {
            players[i].changePosDL();
        }
        else if(parser.input[i]->right && parser.input[i]->down)
        {
            players[i].changePosDR();
        }
    }

}
void Controller::whoIsWinner()
{
    if(players[0].getPlayerHealth() == 0)
    {
        parser.setWinner(2);
    }
    else if(players[1].getPlayerHealth() == 0)
    {
        parser.setWinner(1);
    }
}
void Controller::produceGiftBox()
{
    if(giftBoxNumbers == 0)
    {
        for(int i=0; i<3; i++)
        {
            createGiftBoxes();
        }
    }
}
void Controller::produceNormalBox()
{
    if(normalBoxNumbers<2)
    {
        for(int i=0; i<7; i++)
        {
            createNormalBoxes();
        }

    }

}
void Controller::produceTntBox()
{
    if(tntBoxNumbers<3)
    {
        for(int i=0; i<3; i++)
        {
            createTntBoxes();
        }
    }
}

void Controller::setPlayerNormalBoxesNum()
{
    for(int i = 0; i < this->playerNumbers; i++)
    {
        players[i].setNormalBoxesNum(normalBoxNumbers);
    }

}
void Controller::setPlayerGiftBoxesNum()
{
    for(int i = 0; i < this->playerNumbers; i++)
    {
        players[i].setGiftBoxesNum(giftBoxNumbers);
    }

}
void Controller::setPlayerTntBoxesNum()
{
    for(int i = 0; i < this->playerNumbers; i++)
    {
        players[i].setTntBoxesNum(tntBoxNumbers);
    }
}

void Controller::setPlayerDirection()
{
    for(int i = 0; i < this->playerNumbers; i++)
    {

        if(parser.input[i]->up)
        {
            players[i].setDirection(1);
        }
        else if(parser.input[i]->right)
        {
            players[i].setDirection(2);
        }
        else if(parser.input[i]->down)
        {
            players[i].setDirection(3);
        }
        else if(parser.input[i]->left)
        {
            players[i].setDirection(4);
        }


    }
}

void Controller::setPlayerGiftBoxes()
{

    for(int i=0; i<this->playerNumbers; i++)
    {
        players[i].setGiftBoxVector(gifts);


    }
}
void Controller::setPlayerTntBoxes()
{
    for(int i=0; i<this->playerNumbers; i++)
    {

        players[i].setTntBoxVector(tnts);


    }

}
void Controller::setPlayerNormalBoxes()
{
    for(int i=0; i<this->playerNumbers; i++)
    {

        players[i].setNoramlBoxVector(this->normals);


    }


}
void Controller::setParserGiftBoxNum()
{

    parser.setGiftBoxNum(this->giftBoxNumbers);
}
void Controller::setParserNormalBoxNum()
{

    parser.setNoramlBoxNum(this->normalBoxNumbers);
}
void Controller::setParserTntBoxNum()
{

    parser.setTntBoxNum(this->tntBoxNumbers);
}
void Controller::setParserGiftBoxVector()
{
    parser.setGiftBoxVector(gifts);
}
void Controller::setParserNormalBoxVector()
{
    parser.setNormalBoxVector(normals);
 }
void Controller::setParserTntBoxVector()
{

    parser.setTntBoxVector(tnts);
}
void Controller::setParserPlayerVector()
{
    parser.setPlayerVector(players);
}
void Controller::playerCollisionToGiftBox()
{
    for(int i=0; i<this->playerNumbers; i++)
    {
        if(players[i].playerCollisionGiftBox())
        {
            int giftType;
            giftType = players[i].earnedBox[i].giftType();

            if(giftType == 1)
            {
                players[i].increasePlayerHealth();

            }
            else if(giftType == 2)
            {

                players[i].increaseSpeed();
            }
            else if(giftType == 3)
            {

                players[i].increaseSpeedRate();
            }
            else if(giftType == 4)
            {
                players[i].increaseThrowRate();

            }
        }
        deleteGiftBox();
    }
}
void Controller::playerCollisionToTntBox()
{
    for(int i=0; i<this->playerNumbers; i++)
        {
            if(players[i].playerCollisionTntBox())
            {
                players[i].decreasePlayerHealth();
                deleteTntBox();
            }
        }
}
void Controller::playerCollisionToNormalBox()
{
    for(int i=0; i<this->playerNumbers; i++)
        {
            if(players[i].ownBox==true)
            {
                players[i].tokenBox->player=&players[i];
                players[i].catchBox();
                players[i].tokenBox->moveCatchBox();
            }
              if(players[i].throwBox())
                {
                    while(players[i].tokenBox->getRate()!=0 )
                    {
                        players[i].tokenBox->moveCatchBoxThrow();
                    //  if( players[i].tokenBox->checkCollision()==true)
                        //{
                        //  cout<<"\nthis is playerCollisionToNormalBox\n";
                        //  decreaseAnotherPlayerHealth();
                        //   break;
                        //}
                    }
                    players[i].tokenBox->setDeadOrAlive(0);
                    deleteNormalBox();
                }
            if(players[i].ownBox==false)
                if(players[i].playerBox())
                {
                    players[i].catchBox();
                }

        }
}

void Controller::setZeroToInputs()
{
    for(int i=0; i<this->playerNumbers; i++)
    {
        parser.input[i]->up=0;
        parser.input[i]->down=0;
        parser.input[i]->left=0;
        parser.input[i]->right=0;
        parser.input[i]->space=0;
    }
}

void Controller::setParserPlayerId()
{
    players[0].setId(1);
    players[1].setId(2);
    parser.setPlayerId(players[0].getId(),players[1].getId());
}

void Controller::setPlayerSpaceKey()
{
    for(int i=0; i<this->playerNumbers; i++)
    {
        players[i].setSpace(parser.input[i]->space);

    }

}
void Controller::setWmodelToParser(string s)
{

    parser.setWmodel(s);
}

void Controller::playerCollisionToWall()
{
    int a=0;
    for(int i=0;i<players.size();i++)
       {
           a=players[i].checkCollisionToWall();

           if(a==1)
           {
                parser.input[i]->up=0;

           }
           else if(a==2)
           {
                parser.input[i]->right=0;

           }

           else if(a==3)
           {
                parser.input[i]->down=0;

           }

           else if(a==4)
           {
                 parser.input[i]->left=0;

           }

        }
}

void Controller::checkPlayerCollisionToBox()
{
    int a;

    for(int i=0;i<players.size();i++)
    {
        if(players[i].ownBox==0)
        {
            a=players[i].checkCollisionToBox();
            if(a==1)
            {
                parser.input[i]->up=0;
            }

            else if(a==2)
            {
                parser.input[i]->right=0;
            }

            else if(a==3)
            {
                parser.input[i]->down=0;
            }

            else if(a==4)
            {
                parser.input[i]->left=0;
            }

        }
    }

}

void Controller::decreaseAnotherPlayerHealth()
{
    for(int i=0;i<normals.size();i++)
    {
        if(normals[i].getIsThrow())
        {
            if(players[0].tokenBox == &normals[i])
            {
               players[1].decreasePlayerHealth();
            }

            else if(players[1].tokenBox==&normals[i])
            {
                players[0].decreasePlayerHealth();
            }
         }
    }
}

void Controller::setPlayersVectorToNormalBox()
{
    for(int i=0; i<8;i++)
    {
        normals[i].setPlayerVector(players);
    }

}

