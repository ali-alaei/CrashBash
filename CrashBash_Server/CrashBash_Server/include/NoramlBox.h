#ifndef NORAMLBOX_H
#define NORAMLBOX_H


class NoramlBox:public Box
{
    public:
        NoramlBox();
        virtual ~NoramlBox();
        bool checkCollision();

    protected:

    private:
        bool  owner;
        bool isThrow;
        Player* player;
        int speed;
        int rate;
        bool deadOrAlive;

};

#endif // NORAMLBOX_H
