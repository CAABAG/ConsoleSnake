#include <random>
#include <iostream>
#include "appleclass.h"

char readCharacter(int x, int y);
void goTo(int x, int y);

AppleClass::AppleClass() : mPosStruct {0,0}
{
    int x = getRandomNumber(1, 61);
    int y = getRandomNumber(1, 34);
    while(readCharacter(x, y) != ' ')
    {
        x = getRandomNumber(1, 61);
        y = getRandomNumber(1, 34);
    }
    mPosStruct.posX = x;
    mPosStruct.posY = y;
    std::cout << "@";
}

int AppleClass::getRandomNumber(int minimum, int maximum)
{
    double fraction = 1.0 / (RAND_MAX + 1.0);
    return minimum + static_cast<int>((maximum - minimum + 1) * (std::rand() * fraction));
}

void AppleClass::update()
{
    mPosStruct.posX = getRandomNumber(1, 61);
    mPosStruct.posY = getRandomNumber(1, 34);
    while(readCharacter(mPosStruct.posX, mPosStruct.posY) != ' ')
    {
        mPosStruct.posX = getRandomNumber(1, 61);
        mPosStruct.posY = getRandomNumber(1, 34);
    }
    goTo(mPosStruct.posX, mPosStruct.posY);
    std::cout << "@";
}
