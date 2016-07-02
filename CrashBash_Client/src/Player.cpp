#include "Player.h"


Player::Player()
{
    textureUp.loadFromFile("back-1.png");
    textureDown.loadFromFile("front-1.png");
    textureRight.loadFromFile("right-1.png");
    textureLeft.loadFromFile("left-1.png");
    textureUp2.loadFromFile("back-2.png");
    textureDown2.loadFromFile("front-2.png");
    textureRight2.loadFromFile("right-2.png");
    textureLeft2.loadFromFile("left-2.png");
    textureIcon.loadFromFile("front-1-small.png");
    textureIcon2.loadFromFile("front-2-small.png");
    textureHealthFull.loadFromFile("health-full.png");
    textureHealthEmpty.loadFromFile("health-empty.png");
}

Player::~Player()
{
    //dtor
}
void Player::cinId(int id)
{
    this->id = id;
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

void Player::setId(int id)
{
    this->id=id;
}

sf::Sprite Player::show()
{
    if(id==1)
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

    if(id==2)
    {
        if(direction==1)
        {
            sprite.setTexture(textureUp2);
            sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
            sprite.setPosition(xPos,yPos);
            return sprite;
        }

        else if(direction==2)///right
        {
            sprite.setTexture(textureRight2);
            sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
            sprite.setPosition(xPos,yPos);
            return sprite;
        }

        else if(direction==3)///down
        {
            sprite.setTexture(textureDown2);
            sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
            sprite.setPosition(xPos,yPos);
            return sprite;
        }

        else if(direction==4)///left
        {
            sprite.setTexture(textureLeft2);
            sprite.setTextureRect(sf::IntRect(0, 0, playersize, playersize));
            sprite.setPosition(xPos,yPos);
            return sprite;
        }
    }

}

sf::Sprite Player::showPlayerHealthFull(int x,int y)
{
        sprite.setTexture(textureHealthFull);
        sprite.setTextureRect(sf::IntRect(0, 0, iconSize, iconSize));
        sprite.setPosition(x,y);
        return sprite;
}


sf::Sprite Player::showPlayerHealthEmpty(int x,int y)
{
        sprite.setTexture(textureHealthEmpty);
        sprite.setTextureRect(sf::IntRect(0, 0, iconSize, iconSize));
        sprite.setPosition(x,y);
        return sprite;
}

sf::Sprite Player::showPlayerIcon(int x,int y)
{
    if(id==1)
    {
        sprite.setTexture(textureIcon);
        sprite.setTextureRect(sf::IntRect(0, 0, iconSize, iconSize));
        sprite.setPosition(x,y);
        return sprite;
    }

    if(id==2)
    {
        sprite.setTexture(textureIcon2);
        sprite.setTextureRect(sf::IntRect(0, 0, iconSize, iconSize));
        sprite.setPosition(x,y);
        return sprite;
    }
}

int Player::gethealth()
{
    return health;
}

int Player::getId()
{
    return this->id;
}
