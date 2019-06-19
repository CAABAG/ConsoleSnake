#include "unitclass.h"

UnitClass::UnitClass(const int& x, const int& y, const int& xvel, const int& yvel, const Direction& direction)
                    : mPosStruct{x, y, xvel, yvel, direction}
{
}

int UnitClass::getPosX()            { return mPosStruct.posX; }
int UnitClass::getPosY()            { return mPosStruct.posY; }
Direction UnitClass::getDirection() { return mPosStruct.dir; }
