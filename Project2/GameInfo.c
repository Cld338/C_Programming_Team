#include <stdio.h>
#include <windows.h>
#include "util.h"


void GameInfo() {

    for (int i = 0; i < 3; i++) printf("\n");

    for (int i = 0; i < 50; i++) printf(" ");
    setColor(14);
    printf("게임방법 설명\n");


    for (int i = 0; i < 3; i++) printf("\n");
}