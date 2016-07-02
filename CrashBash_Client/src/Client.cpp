#include "Client.h"

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}
void Client::run()
{
    setPlayerId();
    while(true)
    {
        clearWindow();

       // connection.recieve();     ///ino nemidunam k vaghti server b client vasl mishe client ham bayad vasl beshe ya na.
        parser.deCode();          ///
        graphic.showSurface();
        for(int i=0;i<parser.getNormalBoxNum();i++)
        {
            graphic.showNormalBoxes(parser.normalBoxVector[i]);
        }
        for(int i=0;i<parser.getTntBoxNum();i++)
        {
            graphic.showTntBoxes(parser.tntBoxVector[i]);

        }

        for(int i=0;i<parser.getGiftBoxNum();i++)
        {
            graphic.showGiftBoxes(parser.giftBoxVector[i]);
        }

        for(int i=0;i<parser.getPlayerNum();i++)
        {
            graphic.showPlayers(parser.playerVector[i]);
        }

        showIconAndHealth();
//        cout<<pla
      //  graphic.showPlayersHealth();
      //  player.getKeys();
     //   parser.code();
        //connection.send();
        displayWindow();

    }

}


void Client::showIconAndHealth()
{
    graphic.showPlayerIcon(parser.playerVector[0],firstHeart-80,distanceFromUp);
    if(parser.playerVector[0]->gethealth()==3)
    {
        graphic.showPlayersHealthFull(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    if(parser.playerVector[0]->gethealth()==2)
    {
        graphic.showPlayersHealthFull(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    if(parser.playerVector[0]->gethealth()==1)
    {
        graphic.showPlayersHealthFull(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    if(parser.playerVector[0]->gethealth()==0)
    {
        graphic.showPlayersHealthEmpty(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    graphic.showPlayerIcon(parser.playerVector[1],thirdHeart2+80,distanceFromUp);

    if(parser.playerVector[1]->gethealth()==3)
    {
        graphic.showPlayersHealthFull(parser.playerVector[1],firstHeart2,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[1],secondHeart2,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[1],thirdHeart2,distanceFromUp);
    }

    if(parser.playerVector[1]->gethealth()==2)
    {
        graphic.showPlayersHealthFull(parser.playerVector[1],firstHeart2,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[1],secondHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],thirdHeart2,distanceFromUp);
    }

    if(parser.playerVector[1]->gethealth()==1)
    {
        graphic.showPlayersHealthFull(parser.playerVector[1],firstHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],secondHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],thirdHeart2,distanceFromUp);
    }

    if(parser.playerVector[1]->gethealth()==0)
    {
        graphic.showPlayersHealthEmpty(parser.playerVector[1],firstHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],secondHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],secondHeart2,distanceFromUp);
    }
}

void Client::clearWindow()
{
    graphic.getWindow()->clear();
}

void Client::displayWindow()
{
    graphic.getWindow()->display();
}
void Client::setPlayerId()
{
    int id;
    cout<<"Please Enter your id:";
    cin>>id;
    player.setId(id);
}
