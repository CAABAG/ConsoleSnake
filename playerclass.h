#pragma once

#include "unitclass.h"
#include "pointsclass.h"
#include "appleclass.h"
//#include <list>
//#include <vector>

class PlayerClass : public UnitClass
{
private:
    //std::list<PositionStruct> mPosMemory;
    //std::vector<UnitClass> mBitsOfSnake;
    bool isDead;
    bool hasExited;
public:
    PlayerClass(const int& x, const int& y, const int& xvel, const int& yvel,
                const Direction& direction, const bool& dead, const bool& exit);
    void placeSnake();
    bool died();
    bool exited();
    void handleInput(char input);
    void update(PointsClass& points, const int& x, const int& y, AppleClass& apple);
};
