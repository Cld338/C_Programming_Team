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

	printf("���̵� �Է��ϼ���:");
	scanf("%s", user.id);

	sprintf(filename, "%s.txt", user.id);

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("�� ������Դϴ�. �ʱ� ������ 0�Դϴ�.\n");
		user.score = 0;
	}
	else {

		fscanf(fp, "%d", &user.score);
		printf("��������:%d\n", user.score);
		fclose(fp);

	}

	printf("�̹� ���� ����: +10\n");
	user.score += 10;

	fp = fopen(filename, "w");
	fprintf(fp, "%d\n", user.score);
	fclose(fp);

	printf("������ ����Ǿ����ϴ�! ���� ����: %d\n", user.score);
	return 0;
}


*/