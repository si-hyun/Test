all:pushbox

pushbox:menu.o game.o main.o
	g++ -W -Wall -o pushbox menu.o game.o main.o -lncurses

menu.o:menu.cpp
	g++ -W -Wall -c -o menu.o menu.cpp

game.o:game.cpp
	g++ -W -Wall -c -o game.o game.cpp

main.o:main.cpp
	g++ -W -Wall -c -o main.o main.cpp
