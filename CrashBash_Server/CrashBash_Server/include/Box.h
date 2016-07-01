#ifndef BOX_H
#define BOX_H

class Box
{
    public:
        friend class Player;
        Box(int ,int );

        virtual ~Box();
        virtual bool getDeadOrAlive()=0;///ino mikham too seta kelas box estefade konam

    protected:
        bool deadOrAlive;
        int xPos;
        int yPos;
    private:
};

#endif // BOX_H

