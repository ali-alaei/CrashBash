#ifndef BOX_H
#define BOX_H
#define textureSize 60
#include<string>
#include <SFML/Graphics.hpp>

using namespace std;

class Box
{
    public:
        Box();
        ~Box();
        virtual sf::Sprite show() =0;

    protected:
        int xPos;
        int yPos;
        sf::Texture texture;
        sf::Sprite sprite;
        ///string texture;   ///textures of the boxes.

    private:




};

#endif // BOX_H
