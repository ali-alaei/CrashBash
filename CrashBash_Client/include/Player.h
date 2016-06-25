#ifndef PLAYER_H
#define playersize 200
#define PLAYER_H
#include"Input.h"
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();
        virtual ~Player();
        void getKeys();
        sf::Sprite show();
        void showPlayerHealth();
        void setXPos(int x);
        void setYPos(int y);
        void setHealth(int health);
        void setSpeed(int speed);
        void setDirection(int direction);
        void setThrowRate(int Rate);
        int getSpeed();
    protected:
    private:
        Input playerInputs;
        sf::Texture textureUp;
        sf::Texture textureDown;
        sf::Texture textureRight;
        sf::Texture textureLeft;
        sf::Sprite sprite;
        int xPos;
        int yPos;
        int health;
        int direction;
        int throwRate;
        int speed;
};

#endif // PLAYER_H
