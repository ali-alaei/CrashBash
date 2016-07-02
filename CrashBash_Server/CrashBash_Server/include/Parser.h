#include "string"
#include "iostream"
#include "vector"
#include "Input.h"
#include "Player.h"
#include "TntBox.h"
#include "NoramlBox.h"
#include "GiftBox.h"

using namespace std;

class Parser
{
    public:

        Parser(int );
        vector <Input*> input;
        void code();
        void deCode();
        int getGiftBoxNum();
        int getNoramlBoxNum();
        int getTntBoxNum();
        string getWmodel();
        //vector <Input*>* returnInputs();
        void setGiftBoxNum(int );
        void setNoramlBoxNum(int );
        void setTntBoxNum(int );
        void setGiftBoxVector(const vector <GiftBox> &giftBoxVector);
        void setNormalBoxVector(const vector <NoramlBox> &normalBoxVector);
        void setTntBoxVector(const vector <TntBox> &tntBoxVector);
        void setWinner(int);
        void setPlayerVector(const vector <Player> &playerVector);
        void setPlayerId(int ,int );

    private:

        vector <int> id;

        string wModel;
        int playerNum;
        int giftBoxNum;
        int noramlBoxNum;
        int tntBoxNum;
        int winner;
        vector <Player> playerVector;
        vector <GiftBox> giftBoxVector;
        vector <NoramlBox> noramlBoxVector;
        vector <TntBox>tntBoxVector;

};

