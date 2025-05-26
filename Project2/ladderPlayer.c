#include "ladder.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


void mark_player(int row, int col) {
    int x = 0;
    int y = 0;
    x = (col / 2) * (1 + HORIZONTAL_LENGTH) + col % 2;
    y = (row / 2) * (1 + VERTICAL_LENGTH) + row % 2;
    printf("\b%s", VERTICAL_LINE_CHAR);
    gotoxy(x, y);
    setColor(2);
    printf("��");
    setColor(15);
}

void run(int (*map)[ARR_SIZE][ARR_SIZE]) {
    // Ȯ�ο����� ���� �Լ�
    // ���߿� �ܾ� �Է� �÷� �����ϱ�.
    int x = 0, y = 0;
    print_ladder(map);
    gotoxy(0, 0);
    mark_player(y, x);
    while (1) {
        int ch = _getch();
        int dx = 0, dy = 0;
        if (ch == 224) {
            ch = _getch();
            switch (ch) {
            case 72: dy = -1; break; // ��
            case 80: dy = 1;  break; // ��
            case 75: dx = -1; break; // ��
            case 77: dx = 1;  break; // ��
            }
        }

        int nx = x + dx;
        int ny = y + dy;

        if (nx < 0 || nx >= ARR_SIZE || ny < 0 || ny >= ARR_SIZE)
            continue;
        int next = (*map)[ny][nx];
        if ((next == 1) || (next == 2)) {
            x = nx + dx; //��ġ ����
            y = ny + dy;
            mark_player(y, x);
        }
        else {
            continue;
        }
    }
}
