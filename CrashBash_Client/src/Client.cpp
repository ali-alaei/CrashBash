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
    while(true)
    {

        connection.recieve();     ///ino nemidunam k vaghti server b client vasl mishe client ham bayad vasl beshe ya na.
        parser.deCode();          ///
        graphic.showSurface();
        for(int i=0;i<parser.getNormalBoxNum();i++)
        {
            graphic.showNormalBoxes(*parser.normalBoxVector[i]);
        }
        for(int i=0;i<parser.getTntBoxNum();i++)
        {
            graphic.showTntBoxes(*parser.tntBoxVector[i]);

        }
        for(int i=0;i<parser.getGiftBoxNum();i++)
        {
            graphic.showGiftBoxes(*parser.giftBoxVector[i]);
        }
        for(int i=0;i<2;i++)
        {
            graphic.showPlayers(*parser.playerVector[i]);
        }

        graphic.showPlayersHealth();
        player.getKeys();
        parser.code();
        connection.send();

    }

}
