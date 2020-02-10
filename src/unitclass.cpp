#include "unitclass.h"

UnitClass::UnitClass(const int& x, const int& y, const int& xvel, const int& yvel, const Direction& direction)
                    : mPosStruct{x, y, xvel, yvel, direction} {}

PositionStruct UnitClass::getPositionStruct()   { return mPosStruct; }

void UnitClass::setPositionStruct(PositionStruct pos)
{
    mPosStruct = pos;
}
