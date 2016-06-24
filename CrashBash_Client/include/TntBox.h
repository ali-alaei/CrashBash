#ifndef TNTBOX_H
#define TNTBOX_H
#include"Box.h"

class TntBox : public Box
{
    public:
        TntBox();

        virtual ~TntBox();
        sf::Sprite show();

    protected:

    private:
        string explosionRate;     ///for exploding animation.
};

#endif // TNTBOX_H
