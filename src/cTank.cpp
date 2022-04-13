#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

#include "cTank.h"

cTank::cTank()
    : myLevel(0)
{
}
void cTank::BuildCubicTank(float dim)
{
    myShape.clear();
    myShape.push_back(std::make_pair(0, sqrt(dim)));
    myShape.push_back(std::make_pair(dim, -1));
}

void cTank::BuildPipe( float max )
{
    myShape.clear();
    myShape.push_back(std::make_pair(0, 1));
    myShape.push_back(std::make_pair(max, -1));
}

bool cTank::DeltaFlow(float f)
{
    std::pair<float, float> &lv = myShape[0];
    for (auto &s : myShape)
    {
        if (s.first > myLevel)
            break;
    }
    myLevel += f * lv.second;

    // check for overflow
    if (myLevel > myShape.back().first)
    {
        myLevel = myShape.back().first;
        std::cout << "The tank has overflowed at " << myShape.back().first << "\n";
        return false;
    }

    if (myLevel < 0)
    {
        myLevel = 0;
        std::cout << "The tank has run dry\n";
        return false;
    }
    return true;
}

int cTank::LevelAsPercent() const
{
    return (int)(100. * myLevel / myShape.back().first);
}
