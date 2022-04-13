class cTank
{
public:
    cTank();

    /** Construct tank that is a perfect cube
     * @paramn[in] dim cube dimensions
     */
    void BuildCubicTank(float dim);

    /** Construct pipe tank
     * @param[in] max maximum capacity
     * 
     * This is used when the geometry of the tnk is unknown
     * except for its maximum capacity
     */
    void BuildPipe( float max );

    /** Update tank level
     * @param[in] f total flow into tank ( input - output )
     * @return true if OK, false if tank overflows
     */
    bool DeltaFlow(float f);

    /// Current tank level as a per centage
    int LevelAsPercent() const;

    /// set level
    void Level( int l )
    {
        myLevel = l;
    }

private:
    /** The change in level at a paricular level caused by 1 unit of volume change
     * The change rate is constant from this height to the next height in vector
     * The last element gives the height of a full tank and gives a negative change rate
     * 
     * e.g. a cubic tank would be
     * 0, sqrt(dim)
     * dim, -1
     */
    std::vector<std::pair<float, float>> myShape;

    /// The current level
    int myLevel;
};