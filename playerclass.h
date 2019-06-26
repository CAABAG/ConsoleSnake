#pragma once

#include <list>
#include <vector>
#include <memory>

#include "unitclass.h"
#include "pointsclass.h"
#include "appleclass.h"

class PlayerClass : public UnitClass
{
private:
    bool isDead;
    bool hasExited;
    std::vector<PositionStruct> mPosMemory;
    std::vector<UnitClass> mBitsOfSnake;
public:
    PlayerClass(const int& x, const int& y, const int& xvel, const int& yvel,
                const Direction& direction, const bool& dead, const bool& exit);
    ~PlayerClass();

    void placeSnake();
    bool died();
    bool exited();
    void handleInput(char input);
    void update(PointsClass& points, const int& x, const int& y, AppleClass& apple);
};
