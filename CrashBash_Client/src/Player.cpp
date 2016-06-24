#include "Player.h"


Player::Player()
{
    //ctor
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
