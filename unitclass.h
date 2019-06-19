#pragma once

enum Direction
{
    updir,
    downdir,
    leftdir,
    rightdir
};

struct PositionStruct
{
    int posX;
    int posY;
    int velX;
    int velY;
    Direction dir;
};

class UnitClass
{
private:
    PositionStruct mPosStruct;
public:
    UnitClass(int x, int y, int vel, Direction direction);
    int getPosX();
    int getPosY();
};
