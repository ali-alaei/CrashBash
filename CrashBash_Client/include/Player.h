#ifndef PLAYER_H
#define PLAYER_H
#include"Input.h"
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();
        virtual ~Player();
        void getKeys();
    protected:
    private:
        Input playerInputs;
};

#endif // PLAYER_H
