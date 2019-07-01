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
protected:
    PositionStruct mPosStruct;
public:
    UnitClass(const int& x, const int& y, const int& xvel, const int& yvel, const Direction& direction);

    PositionStruct getPositionStruct();

    void setPositionStruct(PositionStruct pos);
};
