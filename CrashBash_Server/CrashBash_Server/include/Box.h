#ifndef BOX_H
#define BOX_H


class Box
{
    public:
        Box();
        virtual ~Box();
        virtual int updateBox() =0;
    protected:
        int xPos;
        int yPos;

    private:
};

#endif // BOX_H

