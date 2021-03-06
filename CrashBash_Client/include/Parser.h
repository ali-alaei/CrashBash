#include "iostream"
#include "string"
#include "Input.h"
#include "vector"
#include "GiftBox.h"
#include "NormalBox.h"
#include "TntBox.h"
#include "Player.h"

using namespace std;


class Parser
{
    public:
        Parser();
        virtual ~Parser();

        string code();
        void deCode();
        int getGiftBoxNum();
        int getTntBoxNum();
        int getNormalBoxNum();
        int getPlayerNum();
        int getWinner();
        void setWModel(string);
        void def();
        vector <NormalBox*> normalBoxVector;
        vector <TntBox*> tntBoxVector;
        vector <GiftBox*> giftBoxVector;
        vector <Player*> playerVector;
        bool ch;
        Input Input;

    private:

        int giftBoxNum;
        int tntBoxNum;
        int normalBoxNum;
        int playerNum;
        int winner;
        string wModel;
        string lModel;
        string pModel;
};


