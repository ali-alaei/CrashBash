#ifndef NORMALBOX_H
#define NORMALBOX_H
#include"Box.h"

class NormalBox: public Box
{
    public:
        NormalBox();
        virtual ~NormalBox();
        sf::Sprite show();
        void setXPos(int x);
        void setYPos(int y);
    protected:

    private:


};

#endif // NORMALBOX_H
