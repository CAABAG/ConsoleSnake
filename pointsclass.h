#pragma once


class PointsClass
{
private:
    unsigned int mPoints;
public:
    PointsClass(const unsigned int& points);
    void addPoints();
    void showPoints(const int& x, const int& y);
    unsigned int getPoints();
};
