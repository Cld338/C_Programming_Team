#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include "user.h"
#include "ladder.h"
#include "ladderPlayer.h"
#include "util.h"
#include "word.h"
#include "selectGameScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    struct User* user;
    int mode, level=-1;
    int ladder[ARR_SIZE][ARR_SIZE];
    srand(time(NULL));
    hide_cursor();
    titleDraw();
    user = menuDraw();
    if (user == NULL) return 0;
    system("cls");
    hide_cursor();
    mode = selectMode(); // 연습 0, 랭크 1
    system("cls");
    if (mode == 0) level = selectLevel(); // 초급 0, 중급 1, 고급 2
    system("cls");
    printf("모드: %d", mode);
    if (level != -1) printf(", 레벨: %d", level);
    if (user == NULL) return 0;
    while (keyControl() != SUBMIT);
    system("cls");
    create_ladder(ladder);
    char wordlist[NUM][20], word_cholist[NUM][CHO_SIZE], word_jonglist[NUM][JONG_SIZE], word_golist[NUM][GO_SIZE];
    int cho_count = 0, jong_count = 0, go_count = 0;
    make_list(wordlist, word_cholist, word_jonglist, word_golist, &cho_count, &jong_count, &go_count);

    run(ladder, word_cholist, cho_count);
    return 0;
}
