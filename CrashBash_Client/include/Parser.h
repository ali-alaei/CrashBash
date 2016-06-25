#include "iostream"
#include "string"
#include "Input.h"
#include "vector"
#include "Box.h"
#include "Player.h"

using namespace std;


class Parser
{
    public:
        Parser();
        virtual ~Parser();

        string Code();
        void deCode();
        vector <Box*> boxVector;
        vector <Player*> playerVector;
        Input Input;
        int giftBoxNum;
        int tntBoxNum;
        int normalBoxNum;

    private:
        string wModel;
};


