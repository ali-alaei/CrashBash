#ifndef PLAYER_H
#define PLAYER_H
#define boxSize 60
#define playerSize 200
class Player
{
    public:
        GiftBox* earnedBox;
        TntBox* collisionBox;
        Player(int,int);
        virtual ~Player();
        void changePosUp();
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
        void setInputData(Input ); ///remained.
        void setTokenBox(NormalBox ); ///
        void setGiftBoxVector(std::vector <GiftBox> &gifts);
        void setTntBoxVector(std::vector <TntBox> &tnts);
        void setNormalBoxVector(std::vector <NormalBox> &normals);
        ///
    private:
        ///mesalesh dar file alaki
        NoramlBox** normalBoxes;///pointeri be vectore noramlbox ha//=vector.data()
        TntBox** tntBoxes;///pointeri be vectore tntbox ha
        GiftBox** giftBoxes;///pointeri be vectore giftbox ha
        NoramlBox* tokenBox;

        Input* inputData;
        bool ownBox;
        bool deadOrAlive;
        int normalBoxesNum;
        int TntBoxesNum;
        int GiftBoxesNum;
        int health;
        bool space;
        int direction;
        int speed;
        int throwRate;
        int throwSpeed;
        int xPos;
        int yPos;
};

#endif // PLAYER_H
