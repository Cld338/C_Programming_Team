#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include "user.h"
#include "ladder.h"
#include "util.h"
#include "selectGameScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    struct User* user;
    int mode, level;
    srand(time(NULL));
    hide_cursor();
    titleDraw();
    user = menuDraw();
    if (user == NULL) return 0;
    system("cls");
    hide_cursor();
    mode = selectMode(); // ���� 0, ��ũ 1
    system("cls");
    if (mode == 0) level = selectLevel(); // �ʱ� 0, �߱� 1, ��� 2
    system("cls");
    printf("���: %d\n", mode);
    return 0;
}