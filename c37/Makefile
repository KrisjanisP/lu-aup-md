./bin/c37.out: c37.cpp
	g++ -o $@ -I ./include ./lib/fort.c c37.cpp

run: ./bin/c37.out
	clear
	gnome-terminal --window --maximize -- fish -c "./bin/c37.out && read -P \"Press any key to continue...\""