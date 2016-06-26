#include "iostream"
#include "Parser.h"
#include "string"
#include "sstream"
#include "vector"


using namespace std;

Parser::Parser()
{


}
int Parser::getGiftBoxNum()
{

    return this->giftBoxNum;
}
int Parser::getTntBoxNum()
{

    return this->tntBoxNum;
}
int Parser::getNormalBoxNum()
{

    return this->normalBoxNum;
}
/*TntBox* Parser::getTntBoxNum()
{
    return this->tntBoxVector;
}
NormalBox* Parser::getNormalBoxVector()
{
    return this->normalBoxVector;
}
GiftBox* Parser::getGiftBoxVector()
{
    return this->giftBoxVector;

}
Player* Parser::getPlayerVector()
{
    return this->playerVector;
}*/
string Parser::code()
{
    wModel="";
    stringstream Up,Down,Right,Left;

    Up << Input.up;
    Down << Input.down;
    Right << Input.right;
    Left << Input.left;

    wModel = wModel + "U" + Up.str();
    wModel = wModel + "D" + Down.str();
    wModel = wModel + "R" + Right.str();
    wModel = wModel + "L" + Left.str();

    return wModel;
}

void Parser::deCode()
{

    wModel="B|N1,1,1|X1000,800,600|Y900,700,500|*P|X100,200|Y100,200|T5,6|D4,1|H9,1|S2,3|-";
    vector <string> BoxX;
    vector <string> BoxY;
    vector <string> BoxN;
    vector <string> PlayerX;
    vector <string> PlayerY;
    vector <string> PlayerD;
    vector <string> PlayerT;
    vector <string> PlayerH;
    vector <string> PlayerS;

    for(int i=0; ; i++)
    {
        if(wModel[i] != '-')
        {
            if(wModel[i]=='B')
            {
                for(int j=i; ;j++)
                    if(wModel[j]!='*')
                    {
                        if(wModel[j]=='X')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        BoxX.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    BoxX.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        if(wModel[j]=='Y')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        BoxY.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    BoxY.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        if(wModel[j]=='N')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        BoxN.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    BoxN.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                    }
                    else
                        break;
            }

            if(wModel[i]=='P')
            {
                for(int j=i; ; j++)
                    if(wModel[j]!='*')
                    {
                        if(wModel[j]=='X')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        PlayerX.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerX.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        if(wModel[j]=='Y')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        PlayerY.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerY.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        if(wModel[j]=='D')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        PlayerD.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerD.push_back(s);
                                    j=q;
                                    break;
                                }
                            }

                        }
                        if(wModel[j]=='T')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        PlayerT.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerT.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        if(wModel[j]=='H')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        PlayerH.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerH.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        if(wModel[j]=='S')
                        {
                            string s;
                            for(int q=j+1; ; q++)
                            {
                                if(wModel[q]!='|')
                                {
                                    if(wModel[q]==',')
                                    {
                                        cout<<wModel<<endl;
                                        PlayerS.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                    cout<<s<<endl;
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerS.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    else
                        break;
                }
        }
        else if(wModel[i]=='-')
            break;
    }

    int boxNum=BoxX.size();
    int playerNum=PlayerX.size();
    stringstream gb(BoxN[0]);
    gb>>giftBoxNum;
    stringstream nb(BoxN[1]);
    nb>>normalBoxNum;
    stringstream tb(BoxN[2]);
    tb>>tntBoxNum;


    for(int i=0; i<giftBoxNum; i++)
    {
        int a;
        GiftBox* G;

        ///must use if and else for "new"
        G=new GiftBox();

        giftBoxVector.push_back(G);

        stringstream x(BoxX[i]);
        x>>a;

        giftBoxVector[i]->setXPos(a);

        stringstream y(BoxY[i]);
        y>>a;
        giftBoxVector[i]->setYPos(a);

    }


    for(int i=giftBoxNum+1; i<giftBoxNum+normalBoxNum; i++)
    {
        int a;
        NormalBox* N;

        ///must use if and else for "new"
        N=new NormalBox();

        normalBoxVector.push_back(N);

        stringstream x(BoxX[i]);
        x>>a;

        normalBoxVector[i]->setXPos(a);

        stringstream y(BoxY[i]);
        y>>a;
        normalBoxVector[i]->setYPos(a);

    }


    for(int i=giftBoxNum+normalBoxNum+1; i<giftBoxNum+normalBoxNum+tntBoxNum; i++)
    {
        int a;
        TntBox* T;

        ///must use if and else for "new"
        T=new TntBox();

        tntBoxVector.push_back(T);

        stringstream x(BoxX[i]);
        x>>a;

        tntBoxVector[i]->setXPos(a);

        stringstream y(BoxY[i]);
        y>>a;
        tntBoxVector[i]->setYPos(a);

    }

    for(int i=0; i<playerNum; i++)
    {
        int a;
        Player* P;
        P=new Player;
        playerVector.push_back(P);

        stringstream x(PlayerX[i]);
        x>>a;
        playerVector[i]->setXPos(a);

        stringstream y(PlayerY[i]);
        y>>a;
        playerVector[i]->setYPos(a);

        stringstream d(PlayerD[i]);
        d>>a;
        playerVector[i]->setDirection(a);

        stringstream t(PlayerT[i]);
        t>>a;
        playerVector[i]->setThrowRate(a);

        stringstream h(PlayerH[i]);
        h>>a;
        playerVector[i]->setHealth(a);

        stringstream s(PlayerS[i]);
        s>>a;
        playerVector[i]->setSpeed(a);
    }

    //cout<<boxNum<<endl;
    //for(int i=0; i<boxNum; i++)
    //{
    //    cout<<boxVector[i]->xPos<<boxVector[i]->yPos<<endl;
    //}

}


Parser::~Parser()
{

}
