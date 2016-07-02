#include "../include/Connection.h"
#include "iostream"
#include "string"

using namespace std;

Connection::Connection()
{
    port=10000;
}

int Connection::connection()
{
    sf::SocketSelector selector;
    selector.add(Server);

    if (Server.bind(port)!=sf::Socket::Done)
    {
        cout<<"port is busy!";
        return 0;
    }

}

Connection::~Connection()
{
    //dtor
}


string Connection::getReceivingDataA()
{
    return this->ReceivingDataA;
}

string Connection::getReceivingDataB()
{
    return ReceivingDataB;
}

string Connection::getReceivingData()
{
    return ReceivingData;
}

void Connection::setSendingData(string w)
{
    this->SendingData=w;
}

void Connection::send(string w)
{
    this->SendingData = w;

    packet << SendingData;

    Server.send(packet, sf::IpAddress::Broadcast, port);
}

string Connection::receive()
{
    Server.receive(packet, ClientAddress, port);

    packet >> ReceivingData ;

        cout <<"wModel: "<< ReceivingData ;
        return ReceivingData;
}

/*void Connection::receiveA()
{
    int a;

    Server.receive(packet, ClientAddress, port);

    packet >> ReceivingDataA >> a;
    if(a==1)
        cout <<"Ali: "<< ReceivingDataA << "\n" << endl;
    else
        cout <<"Sadegh: "<< ReceivingDataA << "\n" << endl;
}

void Connection::receiveB()
{
    int a;

    Server.receive(packet, ClientAddress , port);

    packet >> ReceivingDataB >> a;
    if(a==2)
        cout <<"Sadegh: "<< ReceivingDataB << "\n" << endl;
    else
        cout <<"Ali: "<< ReceivingDataB << "\n" << endl;

}*/
