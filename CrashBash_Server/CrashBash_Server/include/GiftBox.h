#ifndef GIFTBOX_H
#define GIFTBOX_H
#include "stdlib.h"
#include "time.h"

class GiftBox:public Box
{
    public:
        GiftBox(int , int);
        virtual ~GiftBox();
        int giftType();
    protected:

    private:
        int giftType;
};

#endif // GIFTBOX_H
///anvaee gift:1-afzayeshe joon  2-afzayeshe speed bazikon 3-afzayeshe speede partab 4-afzayeshe borde partab
