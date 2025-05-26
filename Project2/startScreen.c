#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "util.h"

void titleDraw();
int menuDraw();

void titleDraw() {

    for (int i = 0; i < 3; i++) printf("\n");

    for (int i = 0; i < 50; i++) printf(" ");
    setColor(14);
    printf("사다리 탈출 게임\n");


    for (int i = 0; i < 3; i++) printf("\n");
}


int menuDraw() {
    int x = 54;
    int y = 10;

    gotoxy(x - 1, y);
    printf(">게임시작");
    gotoxy(x, y+1);
    printf("게임정보");
    gotoxy(x, y+2);
    printf("  종료  ");
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
            if (y < 12) {
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



