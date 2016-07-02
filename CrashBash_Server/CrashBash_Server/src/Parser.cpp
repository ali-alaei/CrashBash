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

Input& Parser::returnInputs()
{
    return input;
}

void Parser::setGiftBoxNum(int num)
{
    this->giftBoxNum = num;
}

void Parser::setNormalBoxNum(int num)
{
    this->normalBoxNum = num;
}

void Parser::setTntBoxNum(int num)
{
    this->tntBoxNum = num;
}

int Parser::getGiftBoxNum()
{
    return this->getGiftBoxNum;
}

int Parser::getNormalBoxNum()
{
    return this->normalBoxNum;
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
        gb << giftBoxVector[i]->xPos;
        wModel = wModel + gb.str() + ',';
        n++;
    }

    for(int i=0; i<noramlBoxNum; i++)
    {
        stringstream nb;
        nb << noramlBoxVector[i]->xPos;
        wModel = wModel + nb.str() + ',';
        n++;
    }
    for(int i=0; i<tntBoxNum; i++)
    {
        stringstream tb;
        tb << tntBoxVector[i]->xPos;
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
        gb << giftBoxVector[i]->yPos;
        wModel = wModel + gb.str() + ',';
        n++;
    }
    for(int i=0; i<noramlBoxNum; i++)
    {
        stringstream nb;
        nb << noramlBoxVector[i]->yPos;
        wModel = wModel + nb.str() + ',';
        n++;
    }
    for(int i=0; i<tntBoxNum; i++)
    {
        stringstream tb;
        tb << tntBoxVector[i]->yPos;
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
        px<<playerVector[i]->xPos;
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
        py<<playerVector[i]->yPos;
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
        pd<<playerVector[i]->direction;
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
        ph<<playerVector[i]->health;
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
        id << playerVector[i]->id;
        wModel += id;
    }

    wModel+=wi.str();
}

void Parser::deCode()
{
    int a;

    stringstream U(wModel[1]);
    U>>a;
    input->setUp(a);

    stringstream D(wModel[3]);
    D>>a;
    input->setDown(a);

    stringstream R(wModel[5]);
    R>>a;
    input->setRight(a);

    stringstream L(wModel[7]);
    L>>a;
    input->setLeft(a);

    stringstream S(wModel[9]);
    S>>a;
    input->setSpace(a);

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

void setWinner(int w)
{
    this->winner=w;
}






