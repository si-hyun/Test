#include "pushbox.h"

Menu::Menu() {
    // ncurses 준비
    initscr();
    resize_term(17, 40);
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    start_color();

    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
    init_pair(11, COLOR_CYAN, COLOR_BLACK);


    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_RED);
}

int Menu::front() {
    clear();

    // 전체 윈도우
    bkgd(COLOR_PAIR(6));
    border('|','|','-','-','+','+','+','+');
    attron(COLOR_PAIR(11));
    mvprintw(4, 13, "Push Box Game");
    refresh();

    // menu 윈도우
    menu = newwin(10, 12, 6, 15);
    wbkgd(menu, COLOR_PAIR(6));
    mvwprintw(menu, 0, 0, "lEVEL1  1");
    mvwprintw(menu, 1, 0, "lEVEL2  2");
    mvwprintw(menu, 2, 0, "lEVEL3  3");
    mvwprintw(menu, 3, 0, "lEVEL4  4");
    mvwprintw(menu, 4, 0, "lEVEL5  5");
    mvwprintw(menu, 5, 0, "HELP    H");
    mvwprintw(menu, 6, 0, "QUIT    Q");

    wrefresh(menu);

    // menu 입력
    input = 0;
    while(input != 49 && input != 50 && input != 51 && input != 52 && input != 53 && input != 72 && input != 104 && input != 81 && input != 113) {
        input = getch();
        if (input == 49)
            Game game(1);
        else if (input == 50)
            Game game(2);
        else if (input == 51)
            Game game(3);
        else if (input == 52)
            Game game(4);
        else if (input == 53)
            Game game(5);
        else if (input == 72 || input == 104)
            help();
        else if (input == 81 || input == 113) {
            endwin();
            return 0;
        }
    }
    front();
    return 0;
}

void Menu::help() {
    WINDOW *help;
    int input;

    clear();

    // 전체 윈도우
    bkgd(COLOR_PAIR(6));
    border('|','|','-','-','+','+','+','+');
    attron(COLOR_PAIR(7));
    mvprintw(4, 18, "HELP");
    refresh();

    // help 윈도우
    help = newwin(10, 12, 6, 15);
    wbkgd(help, COLOR_PAIR(10));
    mvwprintw(help, 0, 0, "UP      W");
    mvwprintw(help, 1, 0, "DOWN    S");
    mvwprintw(help, 2, 0, "LEFT    A");
    mvwprintw(help, 3, 0, "RIGHT   D");
    wattron(help, COLOR_PAIR(6));
    mvwprintw(help, 4, 0, "RED    YOU");
    wattron(help, COLOR_PAIR(9));
    mvwprintw(help, 5, 0, "YELLOW GOAL");
    wattron(help, COLOR_PAIR(7));
    mvwprintw(help, 6, 0, "GREEN  BOX");
    wattron(help, COLOR_PAIR(10));
    mvwprintw(help, 7, 0, "QUIT   Q");
    wrefresh(help);

    // q 입력 시 종료
    while(input != 81 && input != 113) {
        input = getch();
    }
}