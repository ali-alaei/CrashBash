#ifndef TNTBOX_H
#define TNTBOX_H
#include "Box.h"

class TntBox:public Box
{
    public:
        TntBox(int ,int );
        virtual ~TntBox();
        int getXPos();
        int getYPos();
        bool getDeadOrAlive();


    protected:

    private:

};

#endif // TNTBOX_H
