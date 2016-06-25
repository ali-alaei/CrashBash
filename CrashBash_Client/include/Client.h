#ifndef CLIENT_H
#define CLIENT_H
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
    protected:

    private:
        Graphic graphic;
        Connection connection;
        Parser parser;
        Player player;

};

#endif // CLIENT_H

