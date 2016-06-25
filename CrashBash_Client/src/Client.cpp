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
        graphic.showNormalBoxes();
        graphic.showTntBoxes();
        graphic.showGiftBoxes();
        graphic.showPlayers();
        graphic.showPlayersHealth();
        player.getKeys();
        parser.code();
        connection.send();

    }

}
