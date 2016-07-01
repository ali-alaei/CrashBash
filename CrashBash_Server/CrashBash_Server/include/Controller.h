#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"Player.h"
#include"Input.h"
#include"GiftBox.h"
#include"NoramlBox.h"
#include"TntBox.h"
#include"time.h"
#include<ctime>
#include<cstdlib>
class Controller
{
    public:
        Controller();
        virtual ~Controller();
        ///to create players and their position///
        void createPlayers();
        ///to create boxes and their positions.///
        void createNormalBoxes();
        void createTntBoxes();
        void createGiftBoxes();
        ///...................................///
        void ready();
        ///void checkConnection();
        ///because of udp this function couldnt be used.
        ///to check if any client disconnect stop the game.
        void run();               ///game main while.
        void deleteNormalBox();  ///delete box when they distroyed.
        void deleteTntBox();
        void deleteGiftBox();
        void changePosition();      ///not test yet.
                                    ///change position of the player depending on the inputs.
        bool whoIsWinner();         ///declare winner of the game.
        void produceBox();          ///produce all kind of box whenever needed.
        void decreasePlayerHealth();
        void increasePlayerHealth();
        void increaseThrowRate();      ///depending on the gift type.
        void increaseSpeedRate();
        void increaseSpeed();
        void setPlayerDirection();     ///depending on the inputs.
        void setPlayerInputs();
        ///these are for player class///
        void setPlayerNormalBoxesNum();
        void setPlayerGiftBoxesNum();
        void setPlayerTntBoxesNum();
        void setPlayerDirection();
        void setPlayerTokenBoxes();
        void setPlayerGiftBoxes();
        void setPlayerTntBoxes();
        void setPlayerNormalBoxes();
        void givePlayerGifts();

        ///........................///
        ///these are for Parser class///
        void setParserGiftBoxNum();
        void setParserNormalBoxNum();
        void setParserTntBoxNum();
        void setParserGiftBoxVector();
        void setParserNormalBoxVector();
        void setParserTntBoxVector();
        void setParserPlayerVector();
        ///.........................///
    protected:

    private:
        int playerNumbers;
        int giftBoxNumbers;
        int normalBoxNumbers;
        int tntBoxNumbers;
        std::vector <NoramlBox> normals;
        std::vector <TntBox> tnts;
        std::vector <GiftBox> gifts;
        std::vector <Player> players;
        std::vector <Player> playerInputs;
        //Input* input;    ///it should initialize with the parser input.
        Parser parser(this->playerNumbers);
        Connection connection;


};

#endif // CONTROLLER_H
