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

main()
{
    theSim = new cResSim();
    theSim->BuildPipe(2000000);
    theSim->Level(1000000);

    cResGUI theGUI(theSim);

    return 0;
}
