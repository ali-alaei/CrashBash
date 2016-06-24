#ifndef GRAPHIC_H
#define GRAPHIC_H


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
        Surface *surface;
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
