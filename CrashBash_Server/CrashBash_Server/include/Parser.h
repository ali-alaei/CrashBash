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
        Parser();
        virtual ~Parser();

        void code();
        void deCode();
        int getGiftBoxNum();
        int getNormalBoxNum();
        int getTntBoxNum();
        void setGiftBoxNum();
        void setNormalBoxNum();
        void setTntBoxNum();
        vector <GiftBox*> giftBoxVector;
        vector <NoramlBox*> normalBoxVector;
        vector <TntBox*> tntBoxVector;
        vector <Player*> playerVector;

    private:
        string wModel;
        Input input;
        int playerNum;
        int giftBoxNum;
        int normalBoxNum;
        int tntBoxNum;
};
