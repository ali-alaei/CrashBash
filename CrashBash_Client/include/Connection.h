#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#include <SFML/Network.hpp>
#include <SFML/System/Thread.hpp>
#include <queue>
#include <string>


class Connection
{
public:
    bool error;
    bool connected;
private:
    int ID;
    sf::Mutex log;
    sf::TcpSocket socket;
    sf::Thread sendT;
    sf::Thread receiveT;
    std::queue<sf::Packet> sendQ;
    sf::Mutex sendQmutex;
    std::queue<sf::Packet> receiveQ;
    sf::Mutex receiveQmutex;
    void send();
    void receive();
public:
    Connection();

    void start();
    void sendPacket(sf::Packet);
    sf::Packet receivePacket();
    int haveInQ();
    void end();
    std::string getReceivingData();
    std::string ReceivingData;
private:
};



#endif // CONNECTION_H_INCLUDED
