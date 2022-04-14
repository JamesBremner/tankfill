/// Base class for simulators using tank model
class cBaseSim
{
public:
    void BuildCubicTank(float dim)
    {
        myTank.BuildCubicTank(dim);
    }
    void Build(float dim)
    {
        myTank.BuildPipe(dim);
    }

    virtual bool Step(int deltaFlow)
    {
        return false;
    }

    int LevelAsPercent()
    {
        return myTank.LevelAsPercent();
    }

protected:
    cTank myTank;
};

/// Tank filler simulator
class cTankSim : public cBaseSim
{
public:

    virtual bool Step(int deltaFlow)
    {
        return myTank.DeltaFlow(deltaFlow);
    }
};