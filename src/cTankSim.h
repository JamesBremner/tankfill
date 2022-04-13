class cTankSim
{
public:
    void BuildCubicTank(float dim)
    {
        myTank.BuildCubicTank(dim);
    }
    bool Step( int deltaFlow )
    {
        return myTank.DeltaFlow(deltaFlow);
    }

    int LevelAsPercent()
    {
        return myTank.LevelAsPercent();
    }

private:
    cTank myTank;
};