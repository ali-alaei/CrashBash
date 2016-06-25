#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
    public:
        Connection();
        virtual ~Connection();
        void send();
        void recieve();
        void connnect();

    protected:

    private:
};

#endif // CONNECTION_H
