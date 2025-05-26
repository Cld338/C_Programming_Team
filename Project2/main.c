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
        user = loginScreen();           // 로그인 화면으로
        getchar();
        getchar();
        system("cls");
        //printf("%d", user->score); // user 포인터 받아서 사용
        
        hide_cursor();
        create_ladder(ladder); // 
        run(ladder);
    }
    else if (menu == 1) {
        system("cls");
        GameInfo();      // 게임방법 화면으로
        getchar();
        system("cls");
        // main(); // 좀 이상한데 menuDraw에 menu if문 넣는게 좋을 듯
    }
    else if (menu == 2) {
        system("cls");
    }

    return 0;
}