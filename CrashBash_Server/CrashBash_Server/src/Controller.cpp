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
    for(int i = 0; i < this->playerNumbers; i++)
    {
        Player player;
        players.push_back(player);
    }

}
void Controller::createNormalBoxes()
{
    for(int i = 0; i < this->normalBoxNumbers; i++)
    {
        NoramlBox normalBox;
        normals.push_back(normalBox);

    }


}
void Controller::createTntBoxes()
{
    for(int i = 0; i < this->tntBoxNumbers; i++)
    {
        TntBox tntBox;
        tnts.push_back(tntBox);

    }


}
void Controller::createGiftBoxes()
{
    for(int i = 0; i < this->giftBoxNumbers; i++)
    {
        GifrBox giftBox;
        gifts.push_back(giftBox);

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

void Controller::ready()
{

    if(connection.areClinetsConnect())
    {
        parser.code();
        connection.send();
    }

}
void Controller::checkConnection()
{
    if(connection.isClientDisconnected())
    {
    ///     load a page that says "please wait till another player come again."
    ///     and gamefeatures should stop till another player come.
    ///
    }

}
void Controller::run()
{
    while(true)
    {



    }

}
void Controller::deleteNormalBox()
{
    /*for(int i=0;i<normals.size();i++)
        if(normals[i].isDestroyed())
        {
            ///delete from vectors and all functions that work with this box.
              //it should reduce number of normalboxes.
        }*/


}
void Controller::deleteGiftBox()
{
    /*for(int i=0;i<gifts.size();i++)
        if(normals[i].isDestroyed())
        {
            ///delete from vectors and all functions that work with this box.
            //it should reduce number of giftboxes.
        }*/



}
void Controller::deleteTntBox()
{
        /*for(int i=0;i<tnts.size();i++)
        if(normals[i].isDestroyed())
        {
            ///delete from vectors and all functions that work with this box.
            //it sould reduce number of tntboxes.
        }*/


}
void Controller::changePosition()
{
    for(int i=0; i < playerNumbers; i++)
    {
        if(player[i].isClicked())
        {
            if(player[i].input->up)
            {
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

}
bool Controller::whoIsWinner()
{
    ///this function should check isWin() function of every player
    ///and if it returned true show a page that says player number... won.

}
void Controller::produceBox()
{
    /*if(normals.size()<2)
    {
        ///build some new normal box.
    }*/
    ///this function should do the same work for other kinds of boxes.


}
void Controller::decreasePlayerHealth()
{



}
void Controller::increasePlayerHealth()
{



}
void Controller::setPlayerDirection()
{

    ///with checking inputs I should set the direction of the player.

}
