#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include <stdlib.h>

int main(void) {

    titleDraw();
    int menu = menuDraw();


    if (menu == 0) {
        system("cls");
        loginScreen();           // �α��� ȭ������
    }
    else if (menu == 1) {
        system("cls");
        GameInfo();      // ���ӹ�� ȭ������
    }
    else if (menu == 2) {
        system("cls");

    }

    return 0;
}
