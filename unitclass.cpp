#include "unitclass.h"

UnitClass::UnitClass(int x, int y, int vel, Direction direction) : mPosStruct{x, y, vel, vel, direction}
{
}

int UnitClass::getPosX() { return mPosStruct.posX; }
int UnitClass::getPosY() { return mPosStruct.posY; }
