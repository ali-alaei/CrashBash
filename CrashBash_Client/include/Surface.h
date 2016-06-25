#ifndef SURFACE_H
#define SURFACE_H
#include <SFML/Graphics.hpp>

class Surface
{
    public:
        Surface(int,int);
        virtual ~Surface();
        sf::Sprite show();
    protected:

    private:
        int width;
        int height;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::RenderWindow window;
};

#endif // SURFACE_H
