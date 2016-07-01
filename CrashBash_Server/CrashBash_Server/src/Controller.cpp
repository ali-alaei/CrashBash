#include "Controller.h"

Controller::Controller(): playerNumbers(2),normalBoxNumbers(8),giftBoxNumbers(3),tntBoxNumbers(5)
{



}
Controller::~Controller()
{
    //dtor
}
void Controller::createPlayers()
{
    srand(time(0));
    int x[2];
    int y[2];
    for(int i=0; i < this->playerNumbers; i++)
    {
        x[i] = (rand() %  1081) + 80;
        y[i] = (rand() % 754) + 80;

    }

    for(int i = 0; i < this->playerNumbers; i++)
    {

        players.push_back(Player(x[i],y[i]));
    }

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
        tnts.push_back(GiftBox(x[i],y[i]));

    }

}
void Controller::setPlayerInputs()
{

    playerInputs.push_back(parser.returnInputs());     ///i should debaug it later.
    for(int i = 0; i < playerNumbers; i++)
    {
        players[i]->input = playerInputs[i];

    }
}

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
    connection.connect();
    while(true)
    {
        createPlayers();
        createNormalBoxes();
        createTntBoxes();
        createGiftBoxes();
        setParserGiftBoxNum();
        setParserNormalBoxNum();
        setParserTntBoxNum();
        setParserGiftBoxVector();
        setParserNormalBoxVector();
        setParserTntBoxVector();
        setParserPlayerVector();
        parser.code();
        connection.send();
        connection.recieve();
        setPlayerInputs();
        setPlayerNormalBoxesNum();
        setPlayerGiftBoxesNum();
        setPlayerTntBoxesNum();
        setPlayerDirection();
        setPlayerTokenBoxes();
        setPlayerGiftBoxes();
        setPlayerTntBoxes();
        setPlayerNormalBoxes();
        changePosition();
        playerCollisionToNormalBox();
        playerCollisionToTntBox();
        playerCollisionToGiftBox();
        whoIsWinner();
        setZeroToInputs();
    }

}
void Controller::deleteNormalBox()
{
    for(int i=0; i < normals.size(); i++)
        if(!normals[i].getDeadOrAlive())
        {
            if(i == normals.size()-1)
            {
                normals[i] = NULL;
                break;
            }
            normals[i] = normals[i+1];
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
            if(i == gifts.size()-1)
            {
                gifts[i] = NULL;
                break;
            }
            gifts[i] = gifts[i+1];
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
            if(i == tnts.size()-1)
            {
                tnts[i] = NULL;
                break;
            }
            tnts[i] = tnts[i+1];
            this->tntBoxNumbers--;
            ///delete from vectors and all functions that work with this box.
            //it should reduce number of normalboxes.
        }
}
void Controller::changePosition()
{
    for(int i=0; i < playerNumbers; i++)
    {

            if(player[i].input->up)
            {
                if(player[i].checkCollisionToBox());
                player[i].changePosUp();
            }
            else if(player[i].input->down)
            {
                player[i].changePosDown();
            }
            else if(player[i].input->right)
            {

                player[i].changePosRight();
            }
            else if(player[i].input->left)
            {

                player[i].changePosLeft();
            }
            else if(player[i].input->right && player[i].input->up)
            {

                player[i].changePosUR();
            }
            else if(player[i].input->left && player[i].input->up)
            {

                player[i].changePosUL();
            }
            else if(player[i].input->left && player[i].input->down)
            {
                player[i].changePosDL();

            }
            else if(player[i].inpuut->right && player[i].input->down)
            {
                player[i].changePosDR();
            }
    }

}
int Controller::whoIsWinner()
{
    if(player[0].getPlayerHealth() == 0)
    {
        parser.setWinner(2); ///means player 2 won the game.
    }
    else if(player[1].getPlayerHealth() == 0)
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
void Controller::setPlayerDirection()
{

    ///with checking inputs I should set the direction of the player.

}
void Controller::setPlayerNormalBoxesNum()
{
    for(int i = 0; i < this->playerNumbers: i++)
    {
        players[i].setNormalBoxesNum(normalBoxNumbers);
    }

}
void Controller::setPlayerGiftBoxesNum()
{
    for(int i = 0; i < this->playerNumbers: i++)
    {
        players[i].setGiftBoxesNum(giftBoxNumbers);
    }

}
void Controller::setPlayerTntBoxesNum()
{
    for(int i = 0; i < this->playerNumbers: i++)
    {
        players[i].setTntBoxesNum(tntBoxNumbers);
    }

}
void Controller::setPlayerDirection()
{
    for(int i = 0; i < this->playerNumbers; i++)
    {

        if(players[i].input[i].up)
        {
            players[i].setDirection(1);
        }
        else if(players[i].input[i].right)
        {
            players[i].setDirection(2);
        }
        else if(players[i].input[i].down)
        {
            players[i].setDirection(3);
        }
        else if(players[i].input[i].left)
        {
            players[i].setDirection(4);
        }


    }
}
void Controller::setPlayerTokenBoxes()
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

        players[i].setNormalBoxVector(normals);


    }


}
void Controller::setParserGiftBoxNum()
{

    parser.setGiftBoxNum(this->giftBoxNumbers);
}
void Controller::setParserNormalBoxNum()
{

    parser.setNormalBoxNum(this->normalBoxNumbers);
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
            giftType = players[i].earnedBox[i]->gifType();

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
            if(player[i].playerCollisionTntBox())
            {
                player[i].decreasePlayerHealth();
                deleteTntBox();
            }
        }
}
void Controller::playerCollisionToNormalBox()
{
    for(int i=0; i<this->playerNumbers; i++)
        {
            if(player[i].tokenBox->hasOwner())
            {
                ///move function in normal box will be called.(sadegh)
            }
            if(player[i].playerBox())
            {
                player[i].catchBox();
            }
            player[i].throwBox();
        }
}
void Controller::setInputs()
{

    input.push_back(parser.returnInputs());
}
void Controller::setZeroToInputs()
{
    for(int i=0; i<this->playerNumbers; i++)
    {
        input[i].up=0;
        input[i].down=0;
        input[i].left=0;
        input[i].right=0;
        input[i].space=0;
    }
}
