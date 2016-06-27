#ifndef PLAYER_H
#define PLAYER_H


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
        box* playerBox();
        void catchBox();
        void throwBox();

    protected:

    private:
        NoramlBox* normalboxes;///pointeri be vectore noramlbox ha
        TntBox* tntboxes;///pointeri be vectore tntbox ha
        GiftBox* giftboxes;///pointeri be vectore giftbox ha
        bool up;
        bool down;
        bool right;
        bool left;
        int space;
        bool ownBox;
        int speed;
        int throwRate;
        int throwSpeed;
        bool deadOrAlive;
};

#endif // PLAYER_H
