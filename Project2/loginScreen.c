#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "util.h"

struct User {

    char id[100];
    int score;
};

void loginScreen() {

    for (int i = 0; i < 3; i++) printf("\n");

    for (int i = 0; i < 50; i++) printf(" ");
    setColor(14);
    printf("로그인\n");


    for (int i = 0; i < 3; i++) printf("\n");

	struct User user;
	char filename[120];
	FILE* fp;

	printf("아이디를 입력하세요:");
	scanf("%s", user.id);

	sprintf(filename, "%s.txt", user.id);

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("새 사용자입니다. 초기 점수는 0입니다.\n");
		user.score = 0;
	}
	else {

		fscanf(fp, "%d", &user.score);
		printf("기존점수:%d\n", user.score);
		fclose(fp);

	}
}