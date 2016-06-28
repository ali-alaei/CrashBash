#ifndef BOX_H
#define BOX_H


class Box
{
    public:
        Box(int ,int );
        virtual ~Box();
        bool checkCollisionToPlayer();///ino mikham too seta kelas box estefade konam
        virtual int updateBox() =0;
    protected:
        bool deadOrAlive;
        Player* player;
        int xPos;
        int yPos;

    private:
};

#endif // BOX_H

