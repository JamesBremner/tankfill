#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>
#include "cStarterGUI.h"

#include "cTank.h"
#include "cTankSim.h"



cTankSim theSim;

class cGUI : public cStarterGUI
{
public:
    cGUI();

private:
    wex::label &lbInput;
    wex::label &lbOutput;
    wex::label &lbFill;
    wex::timer *myDriveTimer;

    void draw(wex::shapes &S);
};

    cGUI::cGUI()
        : cStarterGUI(
              "Tank Filler Simulation",
              {50, 50, 500, 500}),
          lbInput(wex::maker::make<wex::label>(fm)),
          lbOutput(wex::maker::make<wex::label>(fm)),
          lbFill(wex::maker::make<wex::label>(fm)),
          myDriveTimer(new wex::timer(fm, 1000))
    {
        lbInput.move(20, 30, 70, 30);
        lbInput.text("Input 1 u/sec");
        lbOutput.move(310, 200, 70, 30);
        lbOutput.text("Output 0 u/sec");
        lbFill.move(200,270,70,30);

        fm.events().draw(
            [&](PAINTSTRUCT &ps)
            {
                wex::shapes S(ps);
                draw(S);
            });

        fm.events().timer(
            [this](int id)
            {
                if (!theSim.Step())
                    delete myDriveTimer;
                lbFill.text("Fill% " + std::to_string(theSim.LevelAsPercent() ));
                fm.update();
            });

        show();
        run();
    }

void cGUI::draw(wex::shapes &S)
{
    S.rectangle({100, 50, 200, 200});
    S.line({20, 60, 110, 60});
    S.line({290, 240, 400, 240});

    S.color(0xffff00);
    S.fill();
    int pixelheight = theSim.LevelAsPercent() * 150 / 100. ;
    std::cout << theSim.LevelAsPercent() << " " << pixelheight << "\n";
    S.rectangle({100, 50 + (150 - pixelheight),
                 200, 50 + pixelheight});
}

main()
{
    theSim.BuildCubicTank(50);

    cGUI theGUI;

    return 0;
}
