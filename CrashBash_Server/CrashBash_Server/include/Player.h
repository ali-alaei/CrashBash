#ifndef PLAYER_H
#define PLAYER_H
#define boxSize 60
#define playerSize 200
class Player
{
    public:
        Player();
        virtual ~Player();
        void changePosUp();
        void changePosDown();
        void changePosRight();
        void changePosLeft();
        void changePosUR();
        void changePosUL();
        void changePosDR();
        void changePosDL();
        void playerBox();///ghablesh box* bood vali b nazaram dge niaz nist
        void catchBox();
        void throwBox();
        void increasePlayerHealth();
        void decreasePlayerHealth();
        void increaseSpeed();
        void increaseSpeedRate();
        void increaseThrowRate()
        void setNormalBoxesNum(int );
        void setSpaceKey(bool);
        void setDirection(int );
        void setInputData(Input );
        void setTokenBox(NormalBox );
        void setGiftBoxVector(GiftBox* );
        void setTntBoxVector(TntBox* );
        void setNormalBoxVector(NoramlBox* );
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
