class cTankSim
{
public:
    void BuildCubicTank(float dim)
    {
        myTank.BuildCubicTank(dim);
    }
    bool Step()
    {
        return myTank.DeltaFlow(1);
    }

    int LevelAsPercent()
    {
        return myTank.LevelAsPercent();
    }

private:
    cTank myTank;
};