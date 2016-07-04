#include "../include/Connection.h"
#include <iostream>
#include "thread"
#include "string"


Connection::Connection() : receiveT(&Connection::receive, this), sendT(&Connection::send, this)
{
    ID = 0;
    connected = false;
    error = false;
}

void Connection::start()
{
    log.lock();
    std::clog <<"Start Connection Number " <<ID <<"\n";
    log.unlock();
    if(ID==0)
    {
        sf::TcpListener listener;
        // bind the listener to a port
        if (listener.listen(53000) != sf::Socket::Done)
        {
            // error...
            log.lock();
            std::cerr <<"Cant Start Listening on Port " <<53000 <<"\n";
            log.unlock();
            error = true;
            return;
        }
        // accept a new connection
        if (listener.accept(socket) != sf::Socket::Done)
        {
            // error...
           log.lock();
            std::cerr <<"connection Number"  <<ID <<"Cant accept tcp Connection\n";
           log.unlock();
            error = true;
            return;
        }
    }
    else
    {
        sf::Socket::Status status = socket.connect("192.168.43.120", 53000);
        if (status != sf::Socket::Done)
        {
            // error...
            std::cerr <<"Cant Connect\n";
            return;
        }
    }
    connected = true;
    log.lock();
    std::clog <<"Client " <<ID <<" successfuly Connected to Serrver\n";
    log.unlock();

    receiveT.launch();
    sendT.launch();
}

void Connection::receive()
{
    while(connected)
    {
        sf::Packet packet;
        if (socket.receive(packet) != sf::Socket::Done)
        {
            // error...
            std::cerr << "ERROR On Receive\n";
        }
        else
            std::clog <<"Receiving...\n";
        receiveQmutex.lock();
        receiveQ.push(packet);
        receiveQmutex.unlock();
    }
}

void Connection::send()
{
    while(connected)
    {
        sf::Packet packet;
        sendQmutex.lock();
        while(sendQ.empty())
        {
            sendQmutex.unlock();
            sf::sleep(sf::milliseconds(10));
            sendQmutex.lock();
        }
        packet = sendQ.front();
        sendQ.pop();
        sendQmutex.unlock();
        if (socket.send(packet) != sf::Socket::Done)
        {
            // error...
            std::cerr << "ERROR On Send\n";
        }
        else
            std::clog <<"Sending...\n";
    }
}

void Connection::sendPacket(sf::Packet packet)
{
    sendQmutex.lock();
    sendQ.push(packet);
    sendQmutex.unlock();
    std::cout <<"attemping to sendQ\n";
}

sf::Packet Connection::receivePacket()
{
    sf::Packet packet;
    receiveQmutex.lock();
    if(!receiveQ.empty())
    {
        packet = receiveQ.front();
        receiveQ.pop();
    }
    receiveQmutex.unlock();
    std::cout <<"attemping to receiveQ\n";
    return packet;
}

int Connection::haveInQ()
{
    if(connected)
    {
        int siz;
        receiveQmutex.lock();
        siz = receiveQ.size();
        receiveQmutex.unlock();
        return siz;
    }
    else
        return 0;
}
