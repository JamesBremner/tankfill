#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>


#include "cTank.h"
#include "cTankSim.h"
#include "cGUI.h"

cBaseSim * theSim;


main()
{
    theSim = new cTankSim();
    theSim->BuildCubicTank(100);

    cGUI theGUI(
        "Tank filler simulation",
        theSim );

    return 0;
}
