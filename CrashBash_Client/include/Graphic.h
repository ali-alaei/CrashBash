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
        void showNormalBoxes(NormalBox* normalBoxObj);
        void showTntBoxes(TntBox* tntBoxObj);
        void showGiftBoxes(GiftBox* giftBoxObj);
        void showPlayers(Player* playerObj);
        void showPlayersHealthFull(Player* playerObj,int ,int);
        void showPlayersHealthEmpty(Player* playerObj,int ,int);
        void showPlayerIcon(Player* playerObj,int ,int);
        sf::RenderWindow* getWindow();
    protected:

    private:
        sf::RenderWindow* window;
        int width;
        int height;
         Surface surface;
        GiftBox *giftbox;
        TntBox *tntbox;
        NormalBox *normalbox;
        Player *player;
};

#endif // GRAPHIC_H
