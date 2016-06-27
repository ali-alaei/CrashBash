#ifndef TNTBOX_H
#define TNTBOX_H


class TntBox:public Box
{
    public:
        TntBox();
        virtual ~TntBox();

    protected:

    private:
        float rate;
        bool deadOrAlive;
};

#endif // TNTBOX_H
