#ifndef NORMALBOX_H
#define NORMALBOX_H
#include"Box.h"

class NormalBox: public Box
{
    public:
        NormalBox();
        virtual ~NormalBox();
        sf::Sprite show();
    protected:

    private:


};

#endif // NORMALBOX_H
