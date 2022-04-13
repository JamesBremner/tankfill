
#include "cStarterGUI.h"

class cGUI : public cStarterGUI
{
public:
    cGUI();

private:
    wex::label &lbInput;
    wex::label &lbOutput;
    wex::label &lbFill;
    wex::slider2& slInput;
    wex::slider2& slOutput;
    wex::timer *myDriveTimer;

    const int tankbottom;

    void draw(wex::shapes &S);
};
