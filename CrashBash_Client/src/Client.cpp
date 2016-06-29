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
//<<<<<<< Updated upstream
         graphic.window->clear();

       // connection.recieve();     ///ino nemidunam k vaghti server b client vasl mishe client ham bayad vasl beshe ya na.
        parser.deCode();          ///
//=======
        cout<<"first of run"<<endl;
        //connection.recieve();     ///ino nemidunam k vaghti server b client vasl mishe client ham bayad vasl beshe ya na.
//>>>>>>> Stashed changes
        graphic.showSurface();
        cout<<"show surface passed"<<endl;          ///
        for(int i=0;i<parser.getNormalBoxNum();i++)
        {

            graphic.showNormalBoxes(parser.normalBoxVector[i]);
            cout<<"first round of normal box show"<<endl;
        }
        cout<<"normal box show passed"<<endl;
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
//        cout<<pla
      //  graphic.showPlayersHealth();
      //  player.getKeys();
     //   parser.code();
        //connection.send();
        graphic.window->display();

    }

}
