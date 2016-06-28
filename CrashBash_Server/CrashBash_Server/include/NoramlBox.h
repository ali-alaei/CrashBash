#ifndef NORAMLBOX_H
#define NORAMLBOX_H
#define boxSize 60
#define playerSize 200

class NoramlBox:public Box
{
    public:
        NoramlBox(int ,int);
        virtual ~NoramlBox();
        void setOwner(bool);
        void setRate(int );
        void setDirection(int);
        void setSpeed(int );
        void setIsThrow(bool);
        void moveCatchBox();
        bool checkCollisionToWallOrRate()
        bool checkCollisionToPlayer();

    protected:

    private:
        bool  owner;
        bool isThrow;
        Player* player;
        Player** playervector;
        int speed;
        int direction;
        int rate;
        bool deadOrAlive;

};

#endif // NORAMLBOX_H
