#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <SFML/Graphics.hpp>
#include <Surface.h>
#include <GiftBox.h>
#include <TntBox.h>
#include <NormalBox.h>
#include <Player.h>

class Graphic
{
    public:
        Graphic();
        virtual ~Graphic();
        sf::Sprite showSurface();
        sf::Sprite showNormalBoxes();
        sf::Sprite showTntBoxes();
        sf::Sprite showGiftBoxe();
        sf::Sprite showPlayers();
        sf::Sprite showPlayersHealth();

    protected:

    private:
        int width;
        int height;
        sf::RenderWindow window;
        Surface surface;
        GiftBox *giftbox;
        TntBox *tntbox;
        NormalBox *normalbox;
        Player *player;
};

#endif // GRAPHIC_H

        ///graphic.showSurface();
        ///window->draw(graphic.showTntBoxes())
        ///graphic.showNormalBoxes();
        ///graphic.showTntBoxes();
        ///graphic.showGiftBoxes();
        ///graphic.showPlayers();
        ///graphic.showPlayersHealth();
