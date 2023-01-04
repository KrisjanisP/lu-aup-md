EXT = external
SRC = src
BDIR = build

$(shell mkdir -p $(BDIR))

CXX = g++
CXXFLAGS = -I ./include

OBJS = $(BDIR)/fort.o $(BDIR)/c37.o

$(BDIR)/c37: $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJS)

$(BDIR)/fort.o: $(EXT)/libfort/lib/fort.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(BDIR)/c37.o: $(SRC)/c37.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/c37.cpp -o $@

run: $(BDIR)/c37
	clear
	gnome-terminal --window --maximize -- bash -c "$^ && read -p \"Press enter to continue\""