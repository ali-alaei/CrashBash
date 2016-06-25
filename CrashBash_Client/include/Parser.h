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
        /*TntBox* getTntBoxVector();
        GiftBox* getGiftBoxVector();
        NormalBox* getNormalBoxVector();
        Player* getPlayerVector();*/
        vector <NormalBox*> normalBoxVector;
        vector <TntBox*> tntBoxVector;
        vector <GiftBox*> giftBoxVector;
        vector <Player*> playerVector;

    private:
        string wModel;
        Input Input;
        int giftBoxNum;
        int tntBoxNum;
        int normalBoxNum;

};


