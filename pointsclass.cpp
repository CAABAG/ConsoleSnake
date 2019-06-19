#include <iostream>

#include "pointsclass.h"

void goTo(int x, int y);
char readCharacter(int x, int y);

PointsClass::PointsClass(const unsigned int& points) : mPoints(points) {}

void PointsClass::addPoints() { mPoints += 10; }

void PointsClass::showPoints(const int& x, const int& y)
{
    goTo(x, y);
    std::cout << getPoints();
}

unsigned int PointsClass::getPoints() { return mPoints; }
