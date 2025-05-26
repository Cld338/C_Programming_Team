// 게임 모드, 난이도 선택인가??
#include "util.h";
#include <stdio.h>;

int selectMode() {
    int x = 54;
    int y = 10;

    gotoxy(x - 1, y);
    printf(">연습");
    gotoxy(x, y + 1);
    printf("랭크");
    while (1) {

        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 10) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 11) {
                gotoxy(x - 1, y);
                printf(" ");
                gotoxy(x - 1, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 10;
        }
        }
    }



}