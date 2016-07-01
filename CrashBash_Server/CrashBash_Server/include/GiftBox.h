#ifndef GIFTBOX_H
#define GIFTBOX_H
#include "stdlib.h"
#include "Box.h"

class GiftBox:public Box
{
    public:
        GiftBox(int , int);
        bool getDeadOrAlive();
      //  virtual ~GiftBox();
        int getXPos();
        int getYPos();
        int giftType();
    protected:

    private:
        int giftTypeNum;

};

#endif // GIFTBOX_H
///anvaee gift:1-afzayeshe joon  2-afzayeshe speed bazikon 3-afzayeshe speede partab 4-afzayeshe borde partab
