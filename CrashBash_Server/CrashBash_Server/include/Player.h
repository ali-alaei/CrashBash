#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        virtual ~Player();

    protected:

    private:
        bool up;
        bool down;
        bool right;
        bool left;
        int space;
        bool haveBoxBool;
};

#endif // PLAYER_H
