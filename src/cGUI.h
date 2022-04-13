
#include "cStarterGUI.h"

class cGUI : public cStarterGUI
{
public:
    cGUI( const std::string& title
    , cBaseSim * sim  );

private:
    wex::label &lbInput;
    wex::label &lbOutput;
    wex::label &lbFill;
    wex::slider2& slInput;
    wex::slider2& slOutput;
    wex::timer *myDriveTimer;
    cBaseSim * mySim;

    const int tankbottom;

    void draw(wex::shapes &S);
};

class cResGUI : public cGUI
{
    public:
    cResGUI( cBaseSim * sim )
    : cGUI("Reservoir Simulation", sim)
    {}
};

