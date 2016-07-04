#include <iostream>
#include"include/Controller.h"

using namespace std;

int main()
{
    srand(time(0));
    Controller gameController;
    gameController.run();

    return 0;
}
