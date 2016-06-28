#include "Parser.h"
#include "string"
#include "iostream"
using namespace std;

Parser::Parser()
{

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
    int boxNum = giftBoxNum+normalBoxNum+tntBoxNum;
    int n=0;

    wModel="";

    wModel+='B';
    wModel = wModel + '|' + 'X';

    for(int i=0; i<giftBoxNum; i++)
    {
        stringstream gb;
        gb << giftBoxVector[i].xPos;
        wModel = wModel + gb.str() + ',';
        n++;
    }
    for(int i=0; i<normalBoxNum; i++)
    {
        stringstream nb;
        nb << normalBoxVector[i].xPos;
        wModel = wModel + nb.str() + ',';
        n++;
    }
    for(int i=0; i<tntBoxNum; i++)
    {
        stringstream tb;
        tb << tntBoxVector[i].xPos;
        wModel = wModel + tb.str();
        if(n!=boxNum)
        wModel += ',';
        n++;
    }
    n=0;


    wModel = wModel + '|' + 'Y';
    for(int i=0; i<giftBoxNum; i++)
    {
        stringstream gb;
        gb << giftBoxVector[i].yPos;
        wModel = wModel + gb.str() + ',';
        n++;
    }
    for(int i=0; i<normalBoxNum; i++)
    {
        stringstream nb;
        nb << normalBoxVector[i].yPos;
        wModel = wModel + nb.str() + ',';
        n++;
    }
    for(int i=0; i<tntBoxNum; i++)
    {
        stringstream tb;
        tb << tntBoxVector[i].yPos;
        wModel = wModel + tb.str();
        if(n!=boxNum)
            wModel += ',';
        n++;
    }
    n=0;
    wModel += '*';

    wModel+='P';
    wModel = wModel + '|' + 'X';
    for(int i=0; i<playerNum; i++)
    {
        stringstream px;
        px<<playerVector[i].xPos;
        wModel = wModel + px.str();
        if(n!=playerNum)
            wModel += ',';
        n++;
    }
    n=0;

    wModel = wModel + '|' + 'Y';
    for(int i=0; i<playerNum; i++)
    {
        stringstream py;
        py<<playerVector[i].yPos;
        wModel = wModel + py.str();
        if(n!=playerNum)
            wModel+=',';
        n++;
    }
    n=0;

    wModel = wModel + '|' + 'D';
    for(int i=0; i<playerNum; i++)
    {
        stringstream pd;
        pd<<playerVector[i].direction;
        wModel = wModel + pd.str();
        if(n!=playerNum)
            wModel += ',';
        n++;
    }
    n=0;

    wModel = wModel + '|' + 'H';
    for(int i=0; i<playerNum; i++)
    {
        stringstream ph;
        ph<<playerVector[i].health;
        wModel = wModel + ph.str();
        if(n!=playerNum)
            wModel += ',';
        n++;
    }
    wModel += '*';

    wModel+='-';
    stringstream p;
    stringstream g;
    stringstream n;
    stringstream t;
    p<<playerNum;
    g<<giftBoxNum;
    n<<normalBoxNum;
    t<<tntBoxNum;
    wModel = wModel + p.str() + g.str() + n.str() + t.str();


    cout<<wModel<<endl;
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

Parser::~Parser()
{

}
