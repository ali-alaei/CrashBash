#include "Parser.h"
#include "string"
#include "iostream"
#include "sstream"
using namespace std;

Parser::Parser(int P)
{
    this->playerNum = P;
    for(int i=0; i<playerNum; i++)
    {
        Input* I;
        I=new Input();
        input.push_back(I);
    }

    for(int i=0; i<playerNum; i++)
    {
        id.push_back(0);
    }

}

/*vector <Input*>* Parser::returnInputs()
{
    return input;
}*/

void Parser::setGiftBoxNum(int num)
{
    this->giftBoxNum = num;
}

void Parser::setNoramlBoxNum(int num)
{
    this->noramlBoxNum = num;
}

void Parser::setTntBoxNum(int num)
{
    this->tntBoxNum = num;
}

int Parser::getGiftBoxNum()
{
    return this->giftBoxNum;
}

int Parser::getNoramlBoxNum()
{
    return this->noramlBoxNum;
}

int Parser::getTntBoxNum()
{
    return this->tntBoxNum;
}

void Parser::code()
{
    int boxNum = giftBoxNum+noramlBoxNum+tntBoxNum;
    int n=0;

    wModel="";

    wModel+='B';
    wModel = wModel + '|' + 'X';

    for(int i=0; i<giftBoxNum; i++)
    {
        stringstream gb;
        gb << giftBoxVector[i].getXPos();
        wModel = wModel + gb.str() + ',';
        n++;
    }

    for(int i=0; i<noramlBoxNum; i++)
    {
        stringstream nb;
        nb << noramlBoxVector[i].getXPos();
        wModel = wModel + nb.str() + ',';
        n++;
    }
    for(int i=0; i<tntBoxNum; i++)
    {
        stringstream tb;
        tb << tntBoxVector[i].getXPos();
        wModel = wModel + tb.str();
        if(n!=boxNum-1)
        wModel += ',';
        n++;
    }
    n=0;

    wModel = wModel + '|' + 'Y';
    for(int i=0; i<giftBoxNum; i++)
    {
        stringstream gb;
        gb << giftBoxVector[i].getYPos();
        wModel = wModel + gb.str() + ',';
        n++;
    }
    for(int i=0; i<noramlBoxNum; i++)
    {
        stringstream nb;
        nb << noramlBoxVector[i].getYPos();
        wModel = wModel + nb.str() + ',';
        n++;
    }
    for(int i=0; i<tntBoxNum; i++)
    {
        stringstream tb;
        tb << tntBoxVector[i].getYPos();
        wModel = wModel + tb.str();
        if(n!=boxNum-1)
            wModel += ',';
        n++;
    }
    n=0;
    wModel+='|';
    wModel += '*';

    wModel+='P';
    wModel = wModel + '|' + 'X';
    for(int i=0; i<playerNum; i++)
    {
        stringstream px;
        px<<playerVector[i].getXPos();
        wModel = wModel + px.str();
        if(n!=playerNum-1)
            wModel += ',';
        n++;
    }
    n=0;


    wModel = wModel + '|' + 'Y';
    for(int i=0; i<playerNum; i++)
    {
        stringstream py;
        py<<playerVector[i].getYPos();
        wModel = wModel + py.str();
        if(n!=playerNum-1)
            wModel+=',';
        n++;
    }
    n=0;

    wModel = wModel + '|' + 'D';
    for(int i=0; i<playerNum; i++)
    {
        stringstream pd;
        pd<<playerVector[i].getDirection();
        wModel = wModel + pd.str();
        if(n!=playerNum-1)
            wModel += ',';
        n++;
    }
    n=0;

    wModel = wModel + '|' + 'H';
    for(int i=0; i<playerNum; i++)
    {
        stringstream ph;
        ph<<playerVector[i].getPlayerHealth();
        wModel = wModel + ph.str();
        if(n!=playerNum-1)
            wModel += ',';
        n++;
    }
    wModel+='|';
    wModel += '*';

    wModel+='-';
    stringstream p;
    stringstream g;
    stringstream no;
    stringstream t;
    stringstream id;
    stringstream wi;
    p << playerNum;
    g << giftBoxNum;
    no << noramlBoxNum;
    t << tntBoxNum;
    wi << winner;

    wModel = wModel + p.str() + g.str() + no.str() + t.str();

    for(int i=0; i<playerNum; i++)
    {
        id << playerVector[i].getId();
        wModel += id.str();
    }

    wModel+=wi.str();
}

void Parser::deCode()
{
    bool a;
    int b;
    string id,u,d,r,l,s;

    id=wModel[wModel.length()-1];

    u=wModel[1];
    d=wModel[3];
    r=wModel[5];
    l=wModel[7];
    s=wModel[9];

    stringstream iid(id);
    iid>>b;

    if(b==1)
    {
        stringstream U(u);
        U>>a;
        input[0]->up=a;

        stringstream D(d);
        D>>a;
        input[0]->down=a;

        stringstream R(r);
        R>>a;
        input[0]->right=a;

        stringstream L(l);
        L>>a;
        input[0]->left=a;

        stringstream S(s);
        S>>a;
        input[0]->space=a;
    }

    if(b==2)
    {
        stringstream U(u);
        U>>a;
        input[1]->up=a;

        stringstream D(d);
        D>>a;
        input[1]->down=a;

        stringstream R(r);
        R>>a;
        input[1]->right=a;

        stringstream L(l);
        L>>a;
        input[1]->left=a;

        stringstream S(s);
        S>>a;
        input[1]->space=a;
    }

}

void Parser::setGiftBoxVector(vector <GiftBox> &giftBoxVector)
{
    for(int i=0; i<giftBoxNum; i++)
    {
        this->giftBoxVector.push_back(giftBoxVector[i]);
    }
}
void Parser::setNormalBoxVector(vector <NoramlBox> &normalBoxVector)
{
    for(int i=0; i<noramlBoxNum; i++)
    {
        this->noramlBoxVector.push_back(noramlBoxVector[i]);
    }
}
void Parser::setTntBoxVector(vector <TntBox> &tntBoxVector)
{
    for(int i=0; i<tntBoxNum; i++)
    {
        this->tntBoxVector.push_back(tntBoxVector[i]);
    }

}
void Parser::setPlayerVector(vector <Player> &playerVector)
{
    for(int i=0; i<playerNum; i++)
    {
        this->playerVector.push_back(playerVector[i]);
    }
}

void Parser::setWinner(int w)
{
    this->winner=w;
}






