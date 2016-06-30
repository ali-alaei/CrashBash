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

        void code();
        void deCode();
        int getGiftBoxNum();
        int getNoramlBoxNum();
        int getTntBoxNum();
        Input* returnInputs();
        void setGiftBoxNum(int );
        void setNoramlBoxNum(int );
        void setTntBoxNum(int );
        vector <GiftBox*> giftBoxVector;
        vector <NoramlBox*> noramlBoxVector;
        vector <TntBox*> tntBoxVector;
        vector <Player*> playerVector;
        vector <int> id;

    private:
        string wModel;
        vector <Input*> input;
        int playerNum;
        int giftBoxNum;
        int noramlBoxNum;
        int tntBoxNum;
};
