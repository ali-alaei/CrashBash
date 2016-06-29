#ifndef BOX_H
#define BOX_H


class Box
{
    public:
        Box(int ,int );

        virtual ~Box();
        virtual bool checkCollisionToPlayer() =0;///ino mikham too seta kelas box estefade konam

    protected:
        bool deadOrAlive;
        int xPos;
        int yPos;
        bool getDeadOrAlive();
    private:
};

#endif // BOX_H

