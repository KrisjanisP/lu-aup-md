SRCDIR = ./src
SRCS = $(SRCDIR)/program.cpp $(SRCDIR)/main.cpp
BINDIR = ./bin
TARGET = $(BINDIR)/d20.out

$(TARGET): $(SRCS)
	mkdir -p $(BINDIR)
	g++ -o $@ $(SRCS)

run: $(TARGET)
	clear
	@$(TARGET)