#ifndef CLIENT_H
#define CLIENT_H
#define distanceFromUp 10
#define firstHeart 240
#define secondHeart 320
#define thirdHeart 400
#define firstHeart2 740
#define secondHeart2 820
#define thirdHeart2 900
#include"Graphic.h"
#include"Parser.h"
#include"Connection.h"
#include"Player.h"
class Client
{
    public:
        Client();
        virtual ~Client();
        void run();
        void clearWindow();
        void displayWindow();
        void showIconAndHealth();
        void setPlayerId();
        void setParserWModel();
    protected:

    private:
        Graphic graphic;
        Connection connection;
        Parser parser;
        Player player;

};

#endif // CLIENT_H

