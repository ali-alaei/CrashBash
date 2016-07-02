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

        Parser parser;

        sf::UdpSocket Server;
        sf::IpAddress ClientAddress;
        unsigned short port;

        int connection();
        void send();
        //void receiveA();
        //void receiveB();
        void receive();
        int getReceivingDataA();
        int getReceivingDataB();
        int getReceivingData();
        void setSendingData();

    private:
        string SendingData;
        string ReceivingDataA;
        string ReceivingDataB;
        string ReceivingData;
        sf::Packet packet;
};

#endif // SERVER_H
