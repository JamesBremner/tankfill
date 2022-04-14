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
        return myTank.DeltaFlow(Rain()-Usage());
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

    /**
     * The water outflow (or usage) per hour is normally distributed with a mean of 6,000 gallons and a standard deviation of 2 gallons
     *  between the hours of 8:00 a.m. and 8:00 p.m.  
     * Water outflow (or usage) is normally distributed with a mean of 500 gallons and a standard deviation of 1 gallon 
     * between the hours of 8:00 p.m. and 8:00 a.m.
     */
    float Usage();
};