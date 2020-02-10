#include <iostream>
#include <conio.h>
#include "playerclass.h"

void goTo(int x, int y);
char readCharacter(int x, int y);

PlayerClass::PlayerClass(const int& x, const int& y, const int& xvel, const int& yvel,
                         const Direction& direction, const bool& dead, const bool& exit)
                        : UnitClass(x, y, xvel, yvel, direction), isDead{dead}, hasExited{exit},
                        mPosMemory {}, mBitsOfSnake {} {}

PlayerClass::~PlayerClass()
{
    if(!mBitsOfSnake.empty())
    {
        for(unsigned int i = 0; i < mBitsOfSnake.size(); i++)
            delete &mBitsOfSnake[i];
    }
}

void PlayerClass::placeSnake()
{
    goTo(mPosStruct.posX, mPosStruct.posY);
    std::cout << "O";
}

bool PlayerClass::died()    { return isDead; }
bool PlayerClass::exited()  { return hasExited; }

void PlayerClass::handleInput(char input)
{
    switch(input)
    {
    case 'w':
        if(mPosStruct.dir == leftdir || mPosStruct.dir == rightdir)
        {
            mPosStruct.dir = updir;
            mPosStruct.velX = 0;
            mPosStruct.velY = -1;
        }
        break;
    case 'a':
        if(mPosStruct.dir == downdir || mPosStruct.dir == updir)
        {
            mPosStruct.dir = leftdir;
            mPosStruct.velX = -1;
            mPosStruct.velY = 0;
        }
        break;
    case 's':
        if(mPosStruct.dir == leftdir || mPosStruct.dir == rightdir)
        {
            mPosStruct.dir = downdir;
            mPosStruct.velX = 0;
            mPosStruct.velY = 1;
        }
        break;
    case 'd':
        if(mPosStruct.dir == downdir || mPosStruct.dir == updir)
        {
            mPosStruct.dir = rightdir;
            mPosStruct.velX = 1;
            mPosStruct.velY = 0;
        }
        break;
    case 'q':
        hasExited = true;
        isDead = true;
        break;
    }
}

void PlayerClass::update(PointsClass& points, const int& x, const int& y, AppleClass& apple)
{
    goTo(mPosStruct.posX, mPosStruct.posY);
    std::cout << " ";
    mPosMemory.insert(mPosMemory.begin(), getPositionStruct());
    mPosStruct.posX += mPosStruct.velX;
    mPosStruct.posY += mPosStruct.velY;
    goTo(mPosStruct.posX, mPosStruct.posY);
    switch(readCharacter(mPosStruct.posX, mPosStruct.posY))
    {
    case ' ':
        std::cout << 'O';
        if(!mBitsOfSnake.empty())
        {
            for(unsigned int i = 0; i < mBitsOfSnake.size(); i++)
            {
                goTo(mBitsOfSnake[i].getPositionStruct().posX, mBitsOfSnake[i].getPositionStruct().posY);
                std::cout << " ";
            }
            for(unsigned int i = 0; i < mBitsOfSnake.size(); i++)
            {
                if(mBitsOfSnake.size() > i)
                {
                    mBitsOfSnake[i].setPositionStruct(mPosMemory[i]);
                }
            }
            for(unsigned int i = 0; i < mBitsOfSnake.size(); i++)
            {
                goTo(mBitsOfSnake[i].getPositionStruct().posX, mBitsOfSnake[i].getPositionStruct().posY);
                std::cout << 'X';
            }
        }
        break;
    case 'X':
        this->isDead = true;
        break;
    case '@':
        points.addPoints();
        points.showPoints(x, y);
        mBitsOfSnake.emplace_back(mPosStruct.posX, mPosStruct.posY, mPosStruct.velX, mPosStruct.velY, mPosStruct.dir);
        goTo(mPosStruct.posX, mPosStruct.posY);
        std::cout << "O";
        apple.update();
        break;
    }
}
