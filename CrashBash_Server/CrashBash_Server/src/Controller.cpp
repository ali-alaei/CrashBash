#include "../include/Controller.h"

Controller::Controller(): playerNumbers(2),normalBoxNumbers(8),giftBoxNumbers(3),tntBoxNumbers(5),parser(this->playerNumbers)
{



}
Controller::~Controller()
{
    //dtor
}
void Controller::createPlayers()
{
    players.push_back(Player(80,80));
    players.push_back(Player(1020,698));
}
void Controller::createNormalBoxes()
{
    srand(time(0));
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
    srand(time(0));
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
   srand(time(0));
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
/*void Controller::setPlayerInputs()
{

    playerInputs.push_back(parser.input);     ///i should debaug it later.
    for(int i = 0; i < playerNumbers; i++)
    {
        players[i].inputData = playerInputs[i];

    }
}*/

/*void Controller::ready()
{


    if(connection.areClinetsConnect())
    {
        parser.code();
        connection.send();
    }

}*/
/*void Controller::checkConnection()
{
    if(connection.isClientDisconnected())
    {
    ///     load a page that says "please wait till another player come again."
    ///     and gamefeatures should stop till another player come.
    ///
    }

}*/

void Controller::run()
{
  //  connection.connect();
    createPlayers();
    cout<<"A";
    createNormalBoxes();
    cout<<"B";
    createTntBoxes();
    cout<<"C";
    createGiftBoxes();
    cout<<"D";

    while(true)
    {
        cout<<"E";
        setParserGiftBoxNum();
        cout<<"F";
        setParserNormalBoxNum();
        cout<<"G";
        setParserTntBoxNum();
        cout<<"H";
        cout<<"I";
        setParserGiftBoxVector();
        setParserNormalBoxVector();
        setParserTntBoxVector();
        setParserPlayerVector();
        setParserPlayerId();
        cout<<"J";

        cout<<"K";

        cout<<"L";
        parser.code();
        //cout<<endl<<parser.wModel<<endl;
        connection.send(parser.getWmodel());
        connection.receive(); ///a function should call.
        //setPlayerInputs();
        cout<<"M";
        setPlayerNormalBoxesNum();
        cout<<"N";
        setPlayerGiftBoxesNum();
        cout<<"O";
        setPlayerTntBoxesNum();
        cout<<"P";
        setPlayerDirection();
        //setPlayerTokenBoxes();
        cout<<"Q";
        setPlayerGiftBoxes();
        cout<<"R";
        setPlayerTntBoxes();
        cout<<"S";
        setPlayerNormalBoxes();
        cout<<"T";
        changePosition();
        cout<<endl<<players[0].getId()<<endl<<players[1].getId()<<endl;

        cout<<"U";
        playerCollisionToNormalBox();
        cout<<"V";
        playerCollisionToTntBox();
        cout<<"W";
        playerCollisionToGiftBox();
        cout<<"X";
        whoIsWinner();
        cout<<"Y";
        setZeroToInputs();
    }

}
void Controller::deleteNormalBox()
{
    for(int i=0; i < normals.size(); i++)
        if(!normals[i].getDeadOrAlive())
        {
            normals.erase(normals.begin()+i);
            this->normalBoxNumbers--;
            ///delete from vectors and all functions that work with this box.
            //it should reduce number of normalboxes.
        }
}
void Controller::deleteGiftBox()
{
     for(int i=0; i < gifts.size(); i++)
        if(!gifts[i].getDeadOrAlive())
        {
            gifts.erase(gifts.begin()+i);
            this->giftBoxNumbers--;
            ///delete from vectors and all functions that work with this box.
            //it should reduce number of normalboxes.
        }
}
void Controller::deleteTntBox()
{
        for(int i=0; i < tnts.size(); i++)
        if(!tnts[i].getDeadOrAlive())
        {
            tnts.erase(tnts.begin()+i);
            this->tntBoxNumbers--;
            ///delete from vectors and all functions that work with this box.
            //it should reduce number of normalboxes.
        }
}
void Controller::changePosition()
{
    for(int i=0; i < playerNumbers; i++)
    {

            if(parser.input[i]->up)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosUp();
                }
            }

            else if(parser.input[i]->down)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosDown();
                }
            }
            else if(parser.input[i]->right)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosRight();
                }
            }
            else if(parser.input[i]->left)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosLeft();
                }
            }
            else if(parser.input[i]->right && parser.input[i]->up)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosUR();
                }
            }
            else if(parser.input[i]->left && parser.input[i]->up)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosUL();
                }
            }
            else if(parser.input[i]->left && parser.input[i]->down)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosDL();
                }
            }
            else if(parser.input[i]->right && parser.input[i]->down)
            {
                if(players[i].checkCollisionToBox())
                {
                    players[i].changePosDR();
                }
            }
    }

}
void Controller::whoIsWinner()
{
    if(players[0].getPlayerHealth() == 0)
    {
        parser.setWinner(2); ///means player 2 won the game.
    }
    else if(players[1].getPlayerHealth() == 0)
    {
        parser.setWinner(1); ///meas player 1 won the game.
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
/*void Controller::setPlayerTokenBoxes()
{
    for(int i = 0; i < this->playerNumbers; i++)
    {
        if(players[i].OwnedBox())
        {
            for(int i = 0; i < this->normalBoxNumbers; i++)
            {
                 if(normals[i].hasOwner())
                 {

                     players[i].setTokenBox(normals[i]);
                 }
            }
        }
    }
}*/
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
            if(players[i].tokenBox->hasOwner())
            {
                ///move function in normal box will be called.(sadegh)
            }
            if(players[i].playerBox())
            {
                players[i].catchBox();
            }
            players[i].throwBox();
        }
}
/*void Controller::setInputs()
{

    playerInputs.push_back(parser.returnInputs());
}*/
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
void Controller::setWmodelToParser()
{
    parser.setWmodel(connection.receive());


}
