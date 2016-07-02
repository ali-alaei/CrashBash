#ifndef SERVER_H
#define SERVER_H
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "Parser.h"
#include <iostream>
#include "string"
using namespace std;

class Connection
{
    public:
        Connection();
        virtual ~Connection();

        sf::UdpSocket Server;
        sf::IpAddress ClientAddress;
        unsigned short port;

        int connection();
        void send(string );
        //void receiveA();
        //void receiveB();
        string receive();
        string getReceivingDataA();
        string getReceivingDataB();
        string getReceivingData();
        void setSendingData(string );

    private:
        string SendingData;
        string ReceivingDataA;
        string ReceivingDataB;
        string ReceivingData;
        sf::Packet packet;
};

#endif // SERVER_H
