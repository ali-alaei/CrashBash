#ifndef NORAMLBOX_H
#define NORAMLBOX_H
#define boxSize 60
#define playerSize 200
#include "Box.h"

class Player;
class NoramlBox:public Box
{
    public:
        NoramlBox(int ,int);
        void moveNormalBox();
        virtual ~NoramlBox();
        void setOwner(bool);
        int getXPos();
        int getYPos();
        void setRate(int );
        void setDirection(int);
        void setSpeed(int );
        void setIsThrow(bool);
        void setPlayersNum(int );
        void moveCatchBox();
        bool checkCollisionToWallOrRate();
        bool checkCollision();
        bool checkCollisionToPlayer();
        bool getDeadOrAlive();
        bool hasOwner();

    protected:

    private:
        Player** playerVector;
        Player* player;
        int playersNum;
        bool owner;
        bool isThrow;
        int speed;
        int direction;
        int rate;


};

#include "Player.h"
#endif // NORAMLBOX_H
