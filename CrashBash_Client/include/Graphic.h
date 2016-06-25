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
        void showSurface();
        void showNormalBoxes();
        void showTntBoxes();
        void showGiftBoxes();
        void showPlayers();
        void showPlayersHealth();

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
