#ifndef PLAYER_H
#define playersize 200
#define iconSize 70
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
        sf::Sprite showPlayerHealthFull(int ,int);
        sf::Sprite showPlayerHealthEmpty(int ,int);
        sf::Sprite showPlayerIcon(int ,int);
        void setXPos(int x);
        void setYPos(int y);
        void setHealth(int health);
        void setSpeed(int speed);
        int gethealth();
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
        sf::Texture textureUp2;
        sf::Texture textureDown2;
        sf::Texture textureRight2;
        sf::Texture textureLeft2;
        sf::Texture textureHealthFull;
        sf::Texture textureHealthEmpty;
        sf::Texture textureIcon;
        sf::Texture textureIcon2;
        sf::Sprite sprite;
        int xPos;
        int id;
        int yPos;
        int health;
        int direction;
        int throwRate;
        int speed;
};

#endif // PLAYER_H
