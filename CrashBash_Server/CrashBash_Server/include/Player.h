#ifndef PLAYER_H
#define PLAYER_H
#define boxSize 60
#define playerSize 200
#include "TntBox.h"
#include "vector"
#include "GiftBox.h"
#include "Input.h"
#include "NoramlBox.h"
class Player
{
    public:
        NoramlBox* tokenBox;
        GiftBox* earnedBox;
        TntBox* collisionBox;
        Player(int,int);
        virtual ~Player();
        void changePosUp();
        int getPlayerHealth();
        int checkCollisionToBox();
        int checkCollisionToWall();
        void changePosDown();
        void changePosRight();
        void changePosLeft();
        void changePosUR();
        void changePosUL();
        void changePosDR();
        void changePosDL();
        bool playerBox();
        bool playerCollisionGiftBox();
        bool playerCollisionTntBox();
        bool OwnedBox();
        void catchBox();
        bool throwBox();
        void increasePlayerHealth();
        void decreasePlayerHealth();
        void increaseSpeed();
        void increaseSpeedRate();
        void increaseThrowRate();
        int getDirection();
        void setNormalBoxesNum(int );
        void setGiftBoxesNum(int );
        void setTntBoxesNum(int );
        void setDirection(int );
        void setInputData(Input  );
        void setGiftBoxVector(std::vector <GiftBox> &gifts);
        void setTntBoxVector(std::vector <TntBox> &tnts);
        void setNoramlBoxVector(std::vector <NoramlBox> &normals);
        void setSpace(bool );
        int getId();
        int getXPos();
        int getYPos();
        void setId(int);
        void setisKeyPressed(bool);
        bool getisKeyPressed();
        bool ownBox;

    private:
        std::vector <NoramlBox*> normalBoxes;
        std::vector <GiftBox*> giftBoxes;
        std::vector <TntBox*> tntBoxes;
        bool deadOrAlive;
        bool isKeyPressedBool;
        int normalBoxesNum;
        int tntBoxesNum;
        int giftBoxesNum;
        int health;
        bool space;
        int direction;
        int speed;
        int throwRate;
        int throwSpeed;
        int xPos;
        int yPos;
        int id;
};
class NoramlBox;
#endif // PLAYER_H
