#include "iostream"
#include "Parser.h"
#include "string"
#include "sstream"
//#include "Input.h"
#include "vector"
//#include "Box.h"
//#include "Player.h"


using namespace std;

Parser::Parser()
{


}

string Parser::Code()
{
    wModel="";
    stringstream Up,Down,Right,Left;

    Up << Input.Up;
    Down << Input.Down;
    Right << Input.Right;
    Left << Input.Left;

    wModel = wModel + "U" + Up.str();
    wModel = wModel + "D" + Down.str();
    wModel = wModel + "R" + Right.str();
    wModel = wModel + "L" + Left.str();

    return wModel;
}

void Parser::deCode()
{

    wModel="B|N1,1,1|X1,2,3|Y3,4,5|*P|X1,2|Y3,4|T5,6|D7,8|H9,1|S2,3|-";
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


    for(int i=0; i<boxNum; i++)
    {
        int a;
        Box* B;
        B=new Box;
        boxVector.push_back(B);

        stringstream x(BoxX[i]);
        x>>a;
        boxVector[i]->xPos=a;

        stringstream y(BoxY[i]);
        y>>a;
        boxVector[i]->yPos=a;

    }
    for(int i=0; i<playerNum; i++)
    {
        int a;
        Player* P;
        P=new Player;
        playerVector.push_back(P);

        stringstream x(PlayerX[i]);
        x>>a;
        playerVector[i]->xPos=a;

        stringstream y(PlayerY[i]);
        y>>a;
        playerVector[i]->yPos=a;

        stringstream d(PlayerD[i]);
        d>>a;
        playerVector[i]->Direction=a;

        stringstream t(PlayerT[i]);
        t>>a;
        playerVector[i]->ThrowRate=a;

        stringstream h(PlayerH[i]);
        h>>a;
        playerVector[i]->Health=a;

        stringstream s(PlayerS[i]);
        s>>a;
        playerVector[i]->Speed=a;;
    }

    cout<<boxNum<<endl;
    for(int i=0; i<boxNum; i++)
    {
        cout<<boxVector[i]->xPos<<boxVector[i]->yPos<<endl;
    }

}


Parser::~Parser()
{

}
