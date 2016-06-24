#ifndef SURFACE_H
#define SURFACE_H


class Surface
{
    public:
        Surface();
        virtual ~Surface();
        sf::RenderWindow renderWindowAccess();
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
