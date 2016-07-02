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
        //friend class Box;
        Input inputData;
        NoramlBox* tokenBox;
        GiftBox* earnedBox;
        TntBox* collisionBox;
        Player(int,int);
        virtual ~Player();
        void changePosUp();
        int getPlayerHealth();
        bool checkCollisionToBox();
        void changePosDown();
        void changePosRight();
        void changePosLeft();
        void changePosUR();
        void changePosUL();
        void changePosDR();
        void changePosDL();
        bool playerBox();///ghablesh box* bood vali b nazaram dge niaz nist
        bool playerCollisionGiftBox();
        bool playerCollisionTntBox();
        bool OwnedBox();
        void catchBox();
        void throwBox();
        void increasePlayerHealth();
        void decreasePlayerHealth();
        void increaseSpeed();
        void increaseSpeedRate();
        void increaseThrowRate();

        ///this should be assigned in controller///
        void setNormalBoxesNum(int );
        void setGiftBoxesNum(int );
        void setTntBoxesNum(int );
        void setDirection(int );
        void setInputData(Input  ); ///remained.
       // void setTokenBox(NoramlBox ); ///
        void setGiftBoxVector(std::vector <GiftBox> &gifts);
        void setTntBoxVector(std::vector <TntBox> &tnts);
        void setNoramlBoxVector(std::vector <NoramlBox> &normals);

        int getXPos();
        int getYPos();
        ///
    private:
        ///mesalesh dar file alaki
        std::vector <NoramlBox*> normalBoxes;///pointeri be vectore noramlbox ha//=vector.data()
        std::vector <GiftBox*> giftBoxes;///pointeri be vectore noramlbox ha//=vector.data()
        std::vector <TntBox*> tntBoxes;///pointeri be vectore noramlbox ha//=vector.data()

       // TntBox** tntBoxes;///pointeri be vectore tntbox ha
        //GiftBox** giftBoxes;///pointeri be vectore giftbox ha

        bool ownBox;
        bool deadOrAlive;
        int normalBoxesNum;
        int tntBoxesNum;
        int giftBoxesNum;
        int health;
        //bool space;
        int direction;
        int speed;
        int throwRate;
        int throwSpeed;
        int xPos;
        int yPos;
};
class NoramlBox;
#endif // PLAYER_H
