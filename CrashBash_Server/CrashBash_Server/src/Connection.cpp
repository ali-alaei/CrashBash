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


int server::getReceivingDataA()
{
    return ReceivingDataA;
}

int server::getReceivingDataB()
{
    return ReceivingDataB;
}

int server::getReceivingData()
{
    return ReceivingData;
}

void server::setSendingData(string w)
{
    this->SendigData=w;
}

void Connection::send()
{
    SendingData = parser.getWmodel();

    packet << SendingData;

    Server.send(packet, sf::IpAddress::Broadcast, port);
}

void Connection::receive()
{
    Server.receive(packet, ClientAddress, port);

    packet >> ReceivingData ;
    if(a==1)
        cout <<"wModel: "<< ReceivingData ;
}

void Connection::receiveA()
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

}
