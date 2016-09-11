#include "Client.h"


Client::Client()
{

}

void Client::run()
{
    setPlayerId();
    connection.start();
    while(connection.haveInQ()==0)
        sf::sleep(sf::milliseconds(20));


    while(true)
    {
        clearWindow();

        graphic.pollEvent();

        if(connection.haveInQ()!=0)
        {
            // cout<<"L";
            string a;
            sf::Packet packet = connection.receivePacket();
            packet >> a;
            setParserWModel(a);
        }
        else
        {
            //cout<<"R"<<endl;
            parser.def();
        }
        Input inp;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            inp.up=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            inp.down=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            inp.left=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            inp.right=true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            inp.space=true;

        parser.Input=inp;
    //connection.start();
     //   connection.receive();
        //else
        //{

           // cout<<"F";
        //}
        //connection

        parser.deCode();

        graphic.showSurface();
        for(int i=0;i<parser.getNormalBoxNum();i++)
        {
            graphic.showNormalBoxes(parser.normalBoxVector[i]);
            //cout<<parser.normalBoxV<<endl;
        }

        for(int i=0;i<parser.getTntBoxNum();i++)
        {
            graphic.showTntBoxes(parser.tntBoxVector[i]);
          //  cout<<"this is tntbox"<<endl;
        }

        for(int i=0;i<parser.getGiftBoxNum();i++)
        {
            graphic.showGiftBoxes(parser.giftBoxVector[i]);
           // cout<<"this is giftbox"<<endl;
        }

        for(int i=0;i<parser.getPlayerNum();i++)
        {
            graphic.showPlayers(parser.playerVector[i]);
           // cout<<"this is player"<<endl;
        }
        showIconAndHealth();
        player.getKeys();
        string a = parser.code();
        if(parser.ch)
        {
            sf::Packet packet ;
            packet << a;
            connection.sendPacket(packet);
        }
        displayWindow();

    }

}


void Client::showIconAndHealth()
{
    graphic.showPlayerIcon(parser.playerVector[0],firstHeart-80,distanceFromUp);
    //cout<<"\nInja  "<<parser.playerVector[0]->gethealth()<<endl;
    //cout<<"Inja  "<<parser.playerVector[1]->gethealth()<<endl;

    if(parser.playerVector[0]->gethealth()==3)
    {
        graphic.showPlayersHealthFull(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    else if(parser.playerVector[0]->gethealth()==2)
    {
        graphic.showPlayersHealthFull(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    else if(parser.playerVector[0]->gethealth()==1)
    {
        graphic.showPlayersHealthFull(parser.playerVector[0],firstHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],secondHeart,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[0],thirdHeart,distanceFromUp);
    }

    else if(parser.playerVector[0]->gethealth()==0)
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

    else if(parser.playerVector[1]->gethealth()==2)
    {
        graphic.showPlayersHealthFull(parser.playerVector[1],firstHeart2,distanceFromUp);
        graphic.showPlayersHealthFull(parser.playerVector[1],secondHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],thirdHeart2,distanceFromUp);
    }

    else if(parser.playerVector[1]->gethealth()==1)
    {
        graphic.showPlayersHealthFull(parser.playerVector[1],firstHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],secondHeart2,distanceFromUp);
        graphic.showPlayersHealthEmpty(parser.playerVector[1],thirdHeart2,distanceFromUp);
    }

    else if(parser.playerVector[1]->gethealth()==0)
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
void Client::setParserWModel(std::string a)
{
    parser.setWModel(a);
}
