#ifndef NORAMLBOX_H
#define NORAMLBOX_H


class NoramlBox:public Box
{
    public:
        NoramlBox();
        virtual ~NoramlBox();

    protected:

    private:
        bool owner;
};

#endif // NORAMLBOX_H
