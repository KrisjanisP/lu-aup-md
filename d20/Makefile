SRCDIR = ./src
SRCS = $(SRCDIR)/program.cpp $(SRCDIR)/main.cpp
BINDIR = ./bin
TARGET = $(BINDIR)/d20.out

$(TARGET): $(SRCS)
	g++ -o $@ $(SRCS)

run: $(TARGET)
	clear
	gnome-terminal -- fish -c "$(TARGET) && read -P \"Press any key to continue...\""