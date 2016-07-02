#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "iostream"
#include "string"
using namespace std;

class Connection
{
    public:
        Connection();
        //virtual ~client();

        sf::UdpSocket Client;
        sf::IpAddress ServerAddress;
        unsigned short port;

        int connection();
        void send();
        string receive();
        string getReceivingData();
        string getSendingData();

        sf::Packet packet;

    private:
        string ReceivingData;
        string SendingData;
};
