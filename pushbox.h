#ifndef NCURSES_PUSHBOX_H
#define NCURSES_PUSHBOX_H

#include <ncurses.h>
#include <iostream>
#include <ncurses.h>
#include <cstring>

class Game {
    WINDOW *game[10][9];
    WINDOW *levelnum;
    WINDOW *push;
    WINDOW *step;
    WINDOW *guide;

    char* leveltag;
    int input;
    int result;
    int pushnum = 0;
    int stepnum = 0;
    int x;
    int y;

    char level[9][10];
    int ifFour = 0;

public:
    Game(int n);
    void setColor();
    int play();
    void searchCharacter();
    void touch_ASDW(int n);
    void score();
};

class Menu {
    WINDOW *menu;
    int input;

public:
    Menu();
    int front();
    void help();
};


#endif //NCURSES_PUSHBOX_H
