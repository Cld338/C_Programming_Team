#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include "user.h"
#include "ladder.h"
#include "ladderPlayer.h"
#include "util.h"
#include "selectGameScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    struct User* user;
    int ladder[ARR_SIZE][ARR_SIZE];
    int mode, level;
    srand(time(NULL));
    hide_cursor();
    titleDraw();
    int menu = menuDraw();
    if (menu == 0) {
        system("cls");
        show_cursor();
        user = loginScreen();           // �α��� ȭ������
        while (keyControl() != SUBMIT);
        system("cls");
        hide_cursor();
        
        mode = selectMode(); // ���� 0, ��ũ 1
        system("cls");
        if (mode == 0) level = selectLevel(); // �ʱ� 0, �߱� 1, ��� 2
        system("cls");
        printf("���: %d\n", mode);
        
    }
    else if (menu == 1) {
        system("cls");
        GameInfo();      // ���ӹ�� ȭ������
        getchar();
        system("cls");
        // main(); // �� �̻��ѵ� menuDraw�� menu if�� �ִ°� ���� ��
    }
    else if (menu == 2) {
        system("cls");
    }

    return 0;
}