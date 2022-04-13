#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>


#include "cTank.h"
#include "cTankSim.h"
#include "cGUI.h"

cGUI::cGUI( const std::string& title,
cBaseSim * sim )
    : cStarterGUI(
          title,
          {50, 50, 500, 500}),
      lbInput(wex::maker::make<wex::label>(fm)),
      lbOutput(wex::maker::make<wex::label>(fm)),
      lbFill(wex::maker::make<wex::label>(fm)),
      slInput(wex::maker::make<wex::slider2>(fm)),
      slOutput(wex::maker::make<wex::slider2>(fm)),
      myDriveTimer(new wex::timer(fm, 1000)),
      mySim( sim ),
      tankbottom(400)
{
    lbInput.move(20, 30, 70, 30);
    lbInput.text("Input: 0");
    lbOutput.move(310, tankbottom-50, 70, 30);
    lbOutput.text("Output 0 u/sec");
    lbFill.move(200, tankbottom+30, 70, 30);
    slInput.move(30,100, 50, 200);
    slInput.range( 0, 10 );
    slInput.position( 0 );
    slInput.vertical();
    slOutput.move(320,100, 50, 200);
    slOutput.range( 0, 10 );
    slOutput.position( 0 );
    slOutput.vertical();



    slInput.events().slid([&](int pos)
    {
        lbInput.text("Input: " + std::to_string( pos ));
        lbInput.update();
    });

    fm.events().draw(
        [&](PAINTSTRUCT &ps)
        {
            wex::shapes S(ps);
            draw(S);
        });

    fm.events().timer(
        [this](int id)
        {
            if (!mySim->Step( 
                slInput.position()-slOutput.position()))
                delete myDriveTimer;
            lbFill.text("Fill% " + std::to_string(mySim->LevelAsPercent()));
            fm.update();
        });

    show();
    run();
}

void cGUI::draw(wex::shapes &S)
{
    const int tanktop    = 50;
    

    S.rectangle({100, tanktop, 200, tankbottom - tanktop});

    S.color(0xffff00);
    S.fill();
    int pixelheight = mySim->LevelAsPercent() * (tankbottom-tanktop) / 100.;
    S.rectangle({101, tankbottom - pixelheight,
                 199, pixelheight});

    S.color( 0 );
    S.line({20, 60, 110, 60});
    S.line({290, tankbottom - 20, 400, tankbottom - 20});
}
