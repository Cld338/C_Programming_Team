#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include "user.h"
#include "ladder.h"
#include "ladderPlayer.h"
#include "util.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    struct User* user;
    int ladder[ARR_SIZE][ARR_SIZE];
    srand(time(NULL));
    hide_cursor();
    titleDraw();
    int menu = menuDraw();
    if (menu == 0) {
        system("cls");
        show_cursor();
        user = loginScreen();           // �α��� ȭ������
        getchar();
        getchar();
        system("cls");
        //printf("%d", user->score); // user ������ �޾Ƽ� ���
        
        hide_cursor();
        create_ladder(ladder); // 
        run(ladder);
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