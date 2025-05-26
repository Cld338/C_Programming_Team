/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


struct User {

	char id[100];
	int score;
};

int main() {

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

	printf("이번 게임 점수: +10\n");
	user.score += 10;

	fp = fopen(filename, "w");
	fprintf(fp, "%d\n", user.score);
	fclose(fp);

	printf("점수가 저장되었습니다! 현재 점수: %d\n", user.score);
	return 0;
}


*/