#include "cTankSim.h"

/// Reservoir simulator
class cResSim : public cBaseSim
{
public:

    cResSim()
    : myStep(0)
    , myProbRain( 20 )
    {

    }

    bool Step( int df )
    {
        myStep++;
        return myTank.DeltaFlow(Rain());
    }

    void Level( float l )
    {
        myTank.Level( l );
    }

private:
    int myStep;
    int myProbRain;     ///< Per cent probability of rain on a day

    /** Simulate rain fall
     * @return reservoir inflow as a result of rain
     * 
     * If it rains on any given day the rainfall-related water inflow to the reservoir that day will average 290,000 gallons,
     * normally distributed with a standard deviation of 100,000 gallons.
     * You can treat this as a single addition to the reservoir at the beginning of each day.
     */
    float Rain();
};