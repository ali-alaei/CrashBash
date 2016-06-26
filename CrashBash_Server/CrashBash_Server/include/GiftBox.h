#ifndef GIFTBOX_H
#define GIFTBOX_H


class GiftBox:public Box
{
    public:
        GiftBox();
        virtual ~GiftBox();
        int giftType();
        void updateBox();
    protected:

    private:
        int giftType;
};

#endif // GIFTBOX_H
