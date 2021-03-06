#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "cTank.h"
#include "cResSim.h"
#include "Probability.h"

cResSim::cResSim()
    : myStep(-1), myProbRain(20), myPeakUsageMean(6000),\
     myNightUsageMean(500)
{
}

float cResSim::Rain()
{
    myLog.rain = false;

    // check for first hour of day
    if ((myStep % 24))
        return 0;

    // check for rain
    if ((rand() % 100) > myProbRain)
        return 0;

    myLog.rain = true;

    // return quantity of inflow due to rain
    return raven::sim::prob::cNormal::ran(
        290000,
        100000);
}
float cResSim::Usage()
{
    int hour = myStep % 24;
    if (8 < hour && hour < 20)
    {
        // peak usage
        return raven::sim::prob::cNormal::ran(
            myPeakUsageMean,
            2);
    }
    else
        return raven::sim::prob::cNormal::ran(
            myNightUsageMean,
            1);
}

bool cResSim::Step(int df)
{
    myStep++;
    if( myStep / 24 == 30 ) {
        Report();
        return false;
    }
    myLog.DayNo = myStep / 24;
    myLog.hour = myStep % 24;
    int prelevel = myTank.Level();
    bool ret = myTank.DeltaFlow(Rain() - Usage());
    if( ! ret )
    {
        // tank ran dry
        // reverse usage
        myTank.Level( prelevel );
    }
    myLog.level = myTank.Level();
    myLog.Write();
    return true;
}
void cResSim::Report()
{
   std::cout << "Water Level end of 30 days with chance of rain at "
    << myProbRain << "% = "
    << myTank.Level() << " gallons\n";
}

cResLog::cResLog()
{
    myf.open("res.log");
    if (!myf.is_open())
        std::cout << "open log failed\n";
}
void cResLog::Write()
{
    myf << DayNo
        << " " << hour
        << " " << level;
    if (rain)
        myf << " RAIN ";
    myf << std::endl;
}