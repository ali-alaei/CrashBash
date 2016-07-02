#include "Connection.h"

Connection::Connection()
{
    port=10000;
    this->ServerAddress="192.168.43.130";
}

string Connection::getReceivingData()
{
    return this->ReceivingData;
}

string Connection::getSendingData()
{
    return this->SendingData;
}

int Connection::connection()
{
    if(Client.bind(port))
    {
        cout<<"OK";
    }
}

void Connection::send()
{

    packet << SendingData;

    Client.send(packet, ServerAddress, port);

}

string Connection::receive()
{
    Client.receive(packet, ServerAddress, port);
    packet >> ReceivingData;
    cout<<"Server: "<<ReceivingData<<endl;
}
