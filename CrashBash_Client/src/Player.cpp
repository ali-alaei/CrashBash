#include "Player.h"


Player::Player()
{
    textureUp.loadFromFile("back-1.png");
    textureDown.loadFromFile("front-1.png");
    textureRight.loadFromFile("right-1.png");
    textureLeft.loadFromFile("left-1.png");
}

Player::~Player()
{
    //dtor
}
void Player::getKeys()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      playerInputs.left = 1;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      playerInputs.right = 1;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      playerInputs.up = 1;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      playerInputs.down = 1;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      playerInputs.space = 1;

    }
}
void Player::setXPos(int x)
{

    this->xPos = x;

}
void Player::setYPos(int y)
{

    this->yPos = y;

}
void Player::setHealth(int health)
{

    this->health = health;

}
void Player::setSpeed(int speed)
{
    this->speed = speed;
}
void Player::setDirection(int direction)
{
    this->direction = direction;
}
int Player::getSpeed()
{
    return this->speed;

}
void Player::setThrowRate(int Rate)
{
    this->throwRate = Rate;
}


sf::Sprite Player::show()
{
    if(direction==1)
    {
        sprite.setTexture(textureUp);
        sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
        sprite.setPosition(xPos,yPos);
        return sprite;
    }

    else if(direction==2)///right
    {
        sprite.setTexture(textureRight);
        sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
        sprite.setPosition(xPos,yPos);
        return sprite;
    }

    else if(direction==3)///down
    {
        sprite.setTexture(textureDown);
        sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
        sprite.setPosition(xPos,yPos);
        return sprite;
    }

    else if(direction==4)///left
    {
        sprite.setTexture(textureLeft);
        sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
        sprite.setPosition(xPos,yPos);
        return sprite;
    }

}

