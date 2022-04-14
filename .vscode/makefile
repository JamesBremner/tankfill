#source file search paths
VPATH = ./src 

	# compiler include search paths
INCS = -I./include \
	-I../ravencode/pub/src \
	-I../windex/include \
	-I../raven-set \
	-I../boost/boost1_72 

LIBS = \
	-lgdiplus -lgdi32 -lcomdlg32 -lstdc++fs \
	#-mwindows

static_link_flags = -static-libstdc++ -static-libgcc -static

# folders
ODIR = ./.vscode/obj
RDIR = ../ravencode/pub/src

OPT = -g
CCflags = -std=c++17 $(OPT) -D_mingw_

# sources
OBJ = \
	$(ODIR)/main.o $(ODIR)/cTank.o $(ODIR)/cGUI.o 

resOBJ = \
	$(ODIR)/reservoir.o $(ODIR)/cTank.o $(ODIR)/cGUI.o \
	$(ODIR)/cResSim.o $(ODIR)/Probability.o


### COMPILE

$(ODIR)/%.o: %.cpp  
	g++  $(CCflags) \
	-c -o $@ $< $(INCS)

tanksim: $(OBJ)
	g++ $(OPT) \
	-o bin/tanksim.exe $^  \
	$(static_link_flags) $(LIBS)

res: $(resOBJ)
	g++ $(OPT) \
	-o bin/reservoirsim.exe $^  \
	$(static_link_flags) $(LIBS)

.PHONY: clean
clean:
	del /q .vscode\\obj\\*.o

