#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"Player.h"
#include"Parser.h"
#include"Input.h"
#include"GiftBox.h"
#include"NoramlBox.h"
#include"Connection.h"
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
        //void ready();
        ///void checkConnection();
        ///because of udp this function couldnt be used.
        ///to check if any client disconnect stop the game.
        void run();               ///game main while.
        void deleteNormalBox();  ///delete box when they distroyed.
        void deleteTntBox();
        void deleteGiftBox();
        void changePosition();      ///not test yet.                                    ///change position of the player depending on the inputs.
        void whoIsWinner();         ///declare winner of the game.
        void produceGiftBox();
        void produceTntBox();
        void produceNormalBox();          ///produce all kind of box whenever needed.
        //void setPlayerInputs();
        ///these are for player class///
        void setPlayerNormalBoxesNum();
        void setPlayerGiftBoxesNum();
        void setPlayerTntBoxesNum();
        void setPlayerDirection();
        //void setPlayerTokenBoxes();
        void setPlayerGiftBoxes();
        void setPlayerTntBoxes();
        void setPlayerNormalBoxes();
        void playerCollisionToTntBox();
        void playerCollisionToGiftBox();
        void playerCollisionToNormalBox();
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
        void setInputs();  ///it should set from parser class.
        void setZeroToInputs();
        void setPlayerSpaceKey();
        void setParserPlayerId();
        void setWmodelToParser();
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
        std::vector <Input> playerInputs;
        //std::vector <Input> input;
        //Input* input;    ///it should initialize with the parser input.
        Parser parser;
        Connection connection;



};

#endif // CONTROLLER_H
