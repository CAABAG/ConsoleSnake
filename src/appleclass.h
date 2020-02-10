#pragma once

struct ApplePosStruct
{
    int posX;
    int posY;
};

class AppleClass
{
private:
    ApplePosStruct mPosStruct;
public:
    AppleClass();

    void update();

    int getRandomNumber(int minimum, int maximum);
};
