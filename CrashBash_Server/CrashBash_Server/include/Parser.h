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
        //vector <Input*>* returnInputs();
        void setGiftBoxNum(int );
        void setNoramlBoxNum(int );
        void setTntBoxNum(int );
        void setGiftBoxVector(vector <GiftBox> &giftBoxVector);
        void setNormalBoxVector(vector <NoramlBox> &normalBoxVector);
        void setTntBoxVector(vector <TntBox> &tntBoxVector);
        void setWinner(int);
        void setPlayerVector(vector <Player> &playerVector);

    private:
        string wModel;
        vector <int> id;

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

