#ifndef NORAMLBOX_H
#define NORAMLBOX_H
#define boxSize 60
#define playerSize 200
#include "Box.h"
#include <vector>
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
        void moveCatchBoxThrow();
        void setDeadOrAlive(bool );
        bool hasOwner();
        int getRate();
        bool getIsThrow();
        void setPlayerVector(std::vector <Player> &players);
        Player* player;
    private:
        std::vector <Player> playerVector;
        int playersNum;
        bool owner;
        bool isThrow;
        int speed;
        int direction;
        int rate;


};

#include "Player.h"
#endif // NORAMLBOX_H
