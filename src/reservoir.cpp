#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>

#include "cTank.h"
#include "cResSim.h"
#include "cGUI.h"
#include "Probability.h"

float cResSim::Rain()
{
    // check for first hour of day
    if ((myStep % 24))
        return 0;

    // check for rain
    if ((rand() % 100) > myProbRain)
        return 0;

    // return quantity of inflow due to rain
    return raven::sim::prob::cNormal::ran(
        290000,
        100000);
}

cResSim *theSim;

main()
{
    theSim = new cResSim();
    theSim->BuildPipe(2000000);
    theSim->Level(1000000);

    cResGUI theGUI(theSim);

    return 0;
}
