// ���� ���, ���̵� �����ΰ�??
#include "util.h";
#include <stdio.h>;

int selectMode() {
    int x = 54;
    int y = 10;

    gotoxy(x - 1, y);
    printf(">����");
    gotoxy(x, y + 1);
    printf("��ũ");
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