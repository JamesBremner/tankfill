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


cResSim *theSim;

main( int argc, char** argv )
{
    // configure the simulation
    theSim = new cResSim();
    theSim->Build(2000000);
    theSim->Level(1000000);
    int rainprob = 20;
    if( argc == 2 )
        rainprob = atoi( argv[1] );
    theSim->RainProbPercent( rainprob );

    // start the GUI, which runs the simulation
    cResGUI theGUI(theSim);

    return 0;
}
