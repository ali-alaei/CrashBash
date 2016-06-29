#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"Player.h"
#include"Input.h"
#include"GiftBox.h"
#include"NoramlBox.h"
#include"TntBox.h"

class Controller
{
    public:
        Controller();
        virtual ~Controller();
        void createPlayers();
        void createNormalBoxes();
        void createTntBoxes();
        void createGiftBoxes();
        void ready();
        void checkConnection();     ///to check if any client disconnect stop the game.
        void run();               ///game main while.
        void deleteNormalBox();  ///delete box when they distroyed.
        void deleteTntBox();
        void deleteGiftBox();
        void changePosition();    ///change position of the player depending on the inputs.
        bool whoIsWinner();         ///declare winner of the game.
        void produceBox();          ///produce all kind of box whenever needed.
        void decreasePlayerHealth();
        void increasePlayerHealth();
        void increaseThrowRate();      ///depending on the gift type.
        void increaseSpeedRate();
        void increaseSpeed();
        void setPlayerDirection();     ///depending on the inputs.
        void setPlayerInputs();

    protected:

    private:
        int playerNumbers;
        int giftBoxNumbers;
        int normalBoxNumbers;
        int tntBoxNumbers;
        vector <NormalBox> normals;
        vector <TntBox> tnts;
        vector <GiftBox> gifts;
        vector <Player> players;
        vector <Player> playerInputs;
        //Input* input;    ///it should initialize with the parser input.
        Parser parser;
        Connection connection;


};

#endif // CONTROLLER_H
