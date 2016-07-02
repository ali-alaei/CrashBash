#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
    public:
        Connection();
        virtual ~Connection();
        bool areClientsConnect();
        bool isClientDisconnected();
        void connect();
        void send();
        void recieve();
    protected:

    private:
};

#endif // CONNECTION_H
