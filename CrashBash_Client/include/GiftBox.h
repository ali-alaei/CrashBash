#ifndef GIFTBOX_H
#define GIFTBOX_H
#include"Box.h"

class GiftBox : public Box
{
    public:
        GiftBox();
        virtual ~GiftBox();
        sf::Sprite show();
    protected:

    private:
        int giftType;   ///to understand type of the gift.server will handle this.
};

#endif // GIFTBOX_H
