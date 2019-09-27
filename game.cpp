#include "pushbox.h"

Game::Game(int n) {
    // level 선택
    if(n == 1) {
        char level1[9][10] = {
                '1','1','1','1','4','4','4','4','4','4',
                '1','3','0','1','1','4','4','4','4','4',
                '1','3','5','0','1','4','4','4','4','4',
                '1','3','0','2','1','4','4','4','4','4',
                '1','1','2','0','1','1','1','4','4','4',
                '4','1','0','2','0','0','1','4','4','4',
                '4','1','0','0','0','0','1','4','4','4',
                '4','1','0','0','1','1','1','4','4','4',
                '4','1','1','1','1','4','4','4','4','4'
        };
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                level[j][i] = level1[j][i];
            }
        }
        leveltag = "LEVEL 1";
    } else if (n == 2){
        char level2[9][10] = {
                '1','1','1','1','1','4','4','4','4','4',
                '1','0','0','0','1','4','4','4','4','4',
                '1','3','3','3','1','4','4','4','4','4',
                '1','2','2','2','1','1','4','4','4','4',
                '1','0','0','0','0','1','4','4','4','4',
                '1','0','5','0','0','1','4','4','4','4',
                '1','1','1','1','1','1','4','4','4','4',
                '4','4','4','4','4','4','4','4','4','4',
                '4','4','4','4','4','4','4','4','4','4'
        };
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                level[j][i] = level2[j][i];
            }
        }
        leveltag = "LEVEL 2";
    } else if (n == 3){
        char level3[9][10] = {
                '1','1','1','1','1','1','1','1','4','4',
                '1','3','0','0','0','0','0','1','4','4',
                '1','0','3','2','2','2','5','1','4','4',
                '1','3','0','0','0','0','0','1','4','4',
                '1','1','1','1','1','0','0','1','4','4',
                '4','4','4','4','1','1','1','1','4','4',
                '4','4','4','4','4','4','4','4','4','4',
                '4','4','4','4','4','4','4','4','4','4',
                '4','4','4','4','4','4','4','4','4','4'
        };
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                level[j][i] = level3[j][i];
            }
        }
        leveltag = "LEVEL 3";
    } else if (n == 4){
        char level4[9][10] = {
                '1','1','1','1','1','1','1','4','4','4',
                '1','0','0','0','0','0','1','4','4','4',
                '1','0','3','2','3','0','1','4','4','4',
                '1','0','2','3','2','0','1','4','4','4',
                '1','0','3','2','3','0','1','4','4','4',
                '1','0','2','3','2','0','1','4','4','4',
                '1','0','0','5','0','0','1','4','4','4',
                '1','1','1','1','1','1','1','4','4','4',
                '4','4','4','4','4','4','4','4','4','4'
        };
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                level[j][i] = level4[j][i];
            }
        }
        leveltag = "LEVEL 4";
        // level4일경우 예외
        ifFour = 1;
    } else if (n == 5){
        char level5[9][10] = {
                '4','1','1','1','1','4','4','4','4','4',
                '4','1','0','0','1','1','1','1','4','4',
                '4','1','0','0','0','0','0','1','1','4',
                '1','1','0','1','1','0','0','0','1','4',
                '1','3','0','3','1','0','5','2','1','1',
                '1','0','0','0','1','0','2','2','0','1',
                '1','0','0','3','1','0','0','0','0','1',
                '1','1','1','1','1','1','1','1','1','1',
                '4','4','4','4','4','4','4','4','4','4'
        };
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 9; j++) {
                level[j][i] = level5[j][i];
            }
        }
        leveltag = "LEVEL 5";
    }

    clear();

    // 전체 윈도우
    bkgd(COLOR_PAIR(6));
    border('|','|','-','-','+','+','+','+');
    attron(COLOR_PAIR(11));
    mvprintw(2, 5, "PUSH BOX GAME");
    refresh();

    // game 윈도우
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 9; y++) {
            game[x][y] = newwin(1, 2, y + 4, x * 2 + 5);
            wrefresh(game[x][y]);
        }
    }
    setColor();

    // levelnum 윈도우
    levelnum = newwin(1, 8, 1, 31);
    wattron(levelnum, COLOR_PAIR(6));
    mvwprintw(levelnum, 0, 0, leveltag);
    wrefresh(levelnum);

    // push 윈도우
    push = newwin(2, 8, 4, 27);
    wbkgd(push, COLOR_PAIR(8));
    mvwprintw(push, 0, 1, "PUSH:");
    mvwprintw(push, 1, 1, "0");
    wrefresh(push);

    // step 윈도우
    step = newwin(2, 8, 11, 27);
    wbkgd(step, COLOR_PAIR(8));
    mvwprintw(step, 0, 1, "STEP:");
    mvwprintw(step, 1, 1, "0");
    wrefresh(step);

    // guide 윈도우
    guide = newwin(1, 8, 15, 30);
    wbkgd(guide, COLOR_PAIR(6));
    mvwprintw(guide, 0, 1, "Q: QUIT");
    wrefresh(guide);

    // 게임 플레이
    result = play();

    // 성공 시 점수 출력
    if (result == 1)
        score();
}

// game 윈도우 색 변경
void Game::setColor() {
    for(int x = 0; x < 10; x++) {
        for (int y = 0; y < 9; y++) {
            switch(level[y][x]) {
                case '0':
                    wbkgd(game[x][y], COLOR_PAIR(0));
                    break;
                case '1':
                    wbkgd(game[x][y], COLOR_PAIR(1));
                    break;
                case '2':
                    wbkgd(game[x][y], COLOR_PAIR(2));
                    break;
                case '3':
                    wbkgd(game[x][y], COLOR_PAIR(3));
                    break;
                case '4':
                    wbkgd(game[x][y], COLOR_PAIR(4));
                    break;
                case '5':
                    wbkgd(game[x][y], COLOR_PAIR(5));
                    break;
            }
            wrefresh(game[x][y]);
        }
    }
}

// 게임 플레이
int Game::play() {
    char pushnum2[10];
    char stepnum2[10];
    int goal[3][2];
    int goal4[6][2];

    // goal 위치 저장
    int i = 0;
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 9; y++) {
            if (level[y][x] == '3') {
                if(ifFour == 1) {
                    goal4[i][0] = x;
                    goal4[i][1] = y;
                    i++;
                } else {
                    goal[i][0] = x;
                    goal[i][1] = y;
                    i++;
                }
            }
        }
    }
    // 모든 goal에 박스('2')가 채워지면 종료
    if(ifFour == 1) {
        while (level[goal4[0][1]][goal4[0][0]] != '2' || level[goal4[1][1]][goal4[1][0]] != '2' ||
               level[goal4[2][1]][goal4[2][0]] != '2' || level[goal4[3][1]][goal4[3][0]] != '2' ||
               level[goal4[4][1]][goal4[4][0]] != '2' || level[goal4[5][1]][goal4[5][0]] != '2') {
            input = getch();
            if (input == 81 || input == 113) // q 입력시 menu로 이동
                return 0;
            searchCharacter();
            touch_ASDW(input);
            if (level[goal4[0][1]][goal4[0][0]] == '0')
                level[goal4[0][1]][goal4[0][0]] = '3';
            if (level[goal4[1][1]][goal4[1][0]] == '0')
                level[goal4[1][1]][goal4[1][0]] = '3';
            if (level[goal4[2][1]][goal4[2][0]] == '0')
                level[goal4[2][1]][goal4[2][0]] = '3';
            if (level[goal4[3][1]][goal4[3][0]] == '0')
                level[goal4[3][1]][goal4[3][0]] = '3';
            if (level[goal4[4][1]][goal4[4][0]] == '0')
                level[goal4[4][1]][goal4[4][0]] = '3';
            if (level[goal4[5][1]][goal4[5][0]] == '0')
                level[goal4[5][1]][goal4[5][0]] = '3';
            setColor();

            // 화면 우측에 push와 step 출력;
            sprintf(pushnum2, "%d", pushnum);
            mvwprintw(push, 1, 1, pushnum2);
            wrefresh(push);
            sprintf(stepnum2, "%d", stepnum);
            mvwprintw(step, 1, 1, stepnum2);
            wrefresh(step);
        }
    } else {
        while (level[goal[0][1]][goal[0][0]] != '2' || level[goal[1][1]][goal[1][0]] != '2' ||
               level[goal[2][1]][goal[2][0]] != '2') {
            input = getch();
            if (input == 81 || input == 113) // q 입력시 menu로 이동
                return 0;
            searchCharacter();
            touch_ASDW(input);
            if (level[goal[0][1]][goal[0][0]] == '0')
                level[goal[0][1]][goal[0][0]] = '3';
            if (level[goal[1][1]][goal[1][0]] == '0')
                level[goal[1][1]][goal[1][0]] = '3';
            if (level[goal[2][1]][goal[2][0]] == '0')
                level[goal[2][1]][goal[2][0]] = '3';
            setColor();

            // 화면 우측에 push와 step 출력;
            sprintf(pushnum2, "%d", pushnum);
            mvwprintw(push, 1, 1, pushnum2);
            wrefresh(push);
            sprintf(stepnum2, "%d", stepnum);
            mvwprintw(step, 1, 1, stepnum2);
            wrefresh(step);
        }
    }
    return 1;
}

// STEP 1
// 캐릭터의 위치 저장
void Game::searchCharacter() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            if (level[j][i] == '5') {
                x = i, y = j;
                break;
            }
        }
    }
}

// STEP 2
// 버튼 클릭
void Game::touch_ASDW(int n) {
    switch (n) {
        // A누르기
        case 97 :
        case 65 :
            stepnum++;
            if (level[y][x-1] == '0' || level[y][x-1] == '3') // 앞이 빈공간, goal일 때
                level[y][x-1] = '5', level[y][x] = '0';
                //앞이 박스일 때
            else if (level[y][x-1] == '2') {
                if (level[y][x-2] == '0' || level[y][x-2] == '3')
                    level[y][x] = '0', level[y][x-1] = '5', level[y][x-2] = '2', pushnum++;
            } else {
                stepnum--;
            }
            // 나머지 경우에는 변화 없음 -> 이 경우에는 이동횟수도 세어주지 말아야 함
            break;

        // S누르기
        case 115 :
        case 83  :
            stepnum++;
            if (level[y+1][x] == '0' || level[y+1][x] == '3') // 앞이 빈공간, goal일 때
                level[y+1][x] = '5', level[y][x] = '0';
                // 앞이 박스일 때
            else if (level[y+1][x] == '2') {
                if (level[y+2][x] == '0' || level[y+2][x] == '3')
                    level[y][x] = '0', level[y+1][x] = '5', level[y+2][x] = '2', pushnum++;
            } else {
                stepnum--;
            }
            break;


        // D누르기
        case 100:
        case 68:
            stepnum++;
            if (level[y][x+1] == '0' || level[y][x+1] == '3') // 앞이 빈공간, goal일 때
                level[y][x+1] = '5', level[y][x] = '0';
                // 앞이 박스일 때
            else if (level[y][x+1] == '2') {
                if (level[y][x+2] == '0' || level[y][x+2] == '3')
                    level[y][x] = '0', level[y][x+1] = '5', level[y][x+2] = '2', pushnum++;
            } else {
                stepnum--;
            }
            break;


        // W누르기
        case 119:
        case 87:
            stepnum++;
            if (level[y-1][x] == '0' || level[y-1][x] == '3') // 앞이 빈공간, goal일 때
                level[y-1][x] = '5', level[y][x] = '0';
                // 앞이 박스일 때
            else if (level[y-1][x] == '2') {
                if (level[y-2][x] == '0' || level[y-2][x] == '3')
                    level[y][x] = '0', level[y-1][x] = '5', level[y-2][x] = '2', pushnum++;
            } else {
                stepnum--;
            }
            break;
    }
}

void Game::score() {
    WINDOW *score;
    char pushnum2[10];
    char stepnum2[10];
    int input;

    clear();

    // 전체 윈도우
    bkgd(COLOR_PAIR(6));
    border('|','|','-','-','+','+','+','+');
    attron(COLOR_PAIR(7));
    mvprintw(4, 18, "SCORE");
    refresh();

    // score 윈도우
    score = newwin(3, 10, 8, 17);
    wbkgd(score, COLOR_PAIR(6));

    // push 출력
    sprintf(pushnum2, "%d", pushnum);
    char printPush[] = "PUSH ";
    strcat(printPush, pushnum2);
    mvwprintw(score, 0, 0, printPush);

    // step 출력
    sprintf(stepnum2, "%d", stepnum);
    char printStep[] = "STEP ";
    strcat(printStep, stepnum2);
    mvwprintw(score, 2, 0, printStep);
    wrefresh(score);

    // guide 윈도우
    guide = newwin(1, 8, 15, 30);
    wbkgd(guide, COLOR_PAIR(6));
    mvwprintw(guide, 0, 1, "Q: QUIT");
    wrefresh(guide);

    // q 입력 시 종료
    while(input != 81 && input != 113) {
        input = getch();
    }
}

