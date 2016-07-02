#include "iostream"
#include "Parser.h"
#include "string"
#include "sstream"
#include "vector"


using namespace std;

Parser::Parser()
{
    for(int i=0; i<10; i++)
    {
        NormalBox* N;
        N=new NormalBox();
        normalBoxVector.push_back(N);

        TntBox* T;
        T=new TntBox();
        tntBoxVector.push_back(T);

        GiftBox* G;
        G=new GiftBox();
        giftBoxVector.push_back(G);
    }
    for(int i=0; i<2; i++)
    {
        Player* P;
        P=new Player;
        playerVector.push_back(P);
    }
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

int Parser::getPlayerNum()
{
    return this->playerNum;
}

string Parser::code()
{
    wModel="";
    stringstream Up,Down,Right,Left,Space,ID;

    Up << Input.up;
    Down << Input.down;
    Right << Input.right;
    Left << Input.left;
    Space << Input.space;
    ID << playerVector[0]->getId();

    wModel = wModel + "U" + Up.str();
    wModel = wModel + "D" + Down.str();
    wModel = wModel + "R" + Right.str();
    wModel = wModel + "L" + Left.str();
    wModel = wModel + "S" + Space.str();
    wModel = wModel + ID.str();

    return wModel;
}

void Parser::deCode()
{

    wModel="B|X900,800,700,600,500,400,300|Y300,400,500,600,700,800,900|*P|X550,750|Y550,740|D2,3|H1,2|*-2322120";
    vector <string> BoxX;
    vector <string> BoxY;
    vector <string> BoxN;
    vector <string> PlayerX;
    vector <string> PlayerY;
    vector <string> PlayerD;
    vector <string> PlayerH;
    vector <string> id;

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
                                        BoxX.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
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
                                        BoxY.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                }
                                else if(wModel[q]=='|')
                                {
                                    BoxY.push_back(s);
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
                                        PlayerX.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
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
                                        PlayerY.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
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
                                        PlayerD.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerD.push_back(s);
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
                                        PlayerH.push_back(s);
                                        s="";
                                        q++;
                                    }
                                    s = s+wModel[q];
                                }
                                else if(wModel[q]=='|')
                                {
                                    PlayerH.push_back(s);
                                    j=q;
                                    break;
                                }
                            }
                        }
                    }
                    else
                        break;
                }
        }
        else if(wModel[i]=='-')
            break;
    }

    string g,n,t,pl,pId,W;
    g=wModel[wModel.length()-(3+2+1)];
    n=wModel[wModel.length()-(2+2+1)];
    t=wModel[wModel.length()-(1+2+1)];
    pl=wModel[wModel.length()-(4+2+1)];
    W=wModel[wModel.length()-1];

    int tmp=0;
    for(int i=2-1; i>=0; i--)
    {
        pId=wModel[wModel.length()-(2-tmp+1)];
        id.push_back(pId);
        tmp++;
    }

    stringstream gb(g);
    gb>>this->giftBoxNum;
    stringstream nb(n);
    nb>>this->normalBoxNum;
    stringstream tb(t);
    tb>>this->tntBoxNum;
    stringstream p(pl);
    p>>this->playerNum;
    stringstream wi(W);
    wi>>this->winner;

    for(int i=0; i<playerNum; i++)
    {
        int d;
        stringstream iid(id[i]);
        iid>>d;
        this->playerVector[i]->setId(d);
    }

    int a;
    for(int i=0; i<giftBoxNum; i++)
    {
        stringstream x(BoxX[i]);
        x>>a;

        giftBoxVector[i]->setXPos(a);

        stringstream y(BoxY[i]);
        y>>a;
        giftBoxVector[i]->setYPos(a);
    }

    for(int i=giftBoxNum, j=0; i<giftBoxNum+normalBoxNum; i++, j++)
    {
        stringstream x1(BoxX[i]);
        x1>>a;
        normalBoxVector[j]->setXPos(a);

        stringstream y(BoxY[i]);
        y>>a;
        normalBoxVector[j]->setYPos(a);
    }

    for(int i=giftBoxNum+normalBoxNum,j=0; i<giftBoxNum+normalBoxNum+tntBoxNum; i++,j++)
    {
        stringstream x(BoxX[i]);
        x>>a;
        tntBoxVector[j]->setXPos(a);

        stringstream y(BoxY[i]);
        y>>a;
        tntBoxVector[j]->setYPos(a);
    }

    for(int i=0; i<playerNum; i++)
    {
        stringstream x(PlayerX[i]);
        x>>a;
        playerVector[i]->setXPos(a);

        stringstream y(PlayerY[i]);
        y>>a;
        playerVector[i]->setYPos(a);

        stringstream d(PlayerD[i]);
        d>>a;
        playerVector[i]->setDirection(a);

        stringstream h(PlayerH[i]);
        h>>a;
        playerVector[i]->setHealth(a);
    }
}


Parser::~Parser()
{

}
