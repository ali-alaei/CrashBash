#ifndef BOX_H
#define BOX_H
#include<string>
using namespace std;

class Box
{
    public:
        Box();
        ~Box();
        virtual void show() const=0;

    protected:
        int xPos;
        int yPos;
        string texture;   ///textures of the boxes.

    private:




};

#endif // BOX_H
