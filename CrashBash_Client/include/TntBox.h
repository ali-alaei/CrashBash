#ifndef TNTBOX_H
#define TNTBOX_H
#include"Box.h"

class TntBox : public Box
{
    public:
        TntBox();

        virtual ~TntBox();
        sf::Sprite show();
        void setXPos(int x);
        void setYPos(int y);
    protected:

    private:
        string explosionRate;     ///for exploding animation.
};

#endif // TNTBOX_H
