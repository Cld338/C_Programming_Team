#include "word.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
/*
int main()
{
	char wordlist[NUM][20], word_cholist[NUM][CHO_SIZE], word_jonglist[NUM][JONG_SIZE], word_golist[NUM][GO_SIZE];
	int cho_count = 0, jong_count = 0, go_count = 0;
	make_list(wordlist, word_cholist, word_jonglist, word_golist, &cho_count, &jong_count, &go_count);
	int ch;
	while (1) {
		system("cls");
		printf("1. 초급\n2. 중급\n3. 고급\n4. 종료\n");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			cho_practice(word_cholist, cho_count);
			break;
		case 2:
			jong_practice(word_jonglist, jong_count);
			break;
		case 3:
			go_practice(word_golist, go_count);
			break;
		case 4:
			return 0;
		}
	}

}
*/

//--------------파일에서 문장열 불러와서 각 배열에 저장하기--------------------------------------------------------------

void make_list(char (*w)[20], char (*cw)[CHO_SIZE], char (*jw)[JONG_SIZE], char (*gw)[GO_SIZE], int* cc, int* jc, int* gc) {
	int i;
	FILE* f;
	f = fopen("wordlist.txt", "r"); //파일 불러오기
	for (i = 0; i < NUM - 1; i++) {
		fscanf(f, "%s", w[i]); //파일에 있는 내용 word 변수에 저장
		if (strlen(w[i]) == CHO_SIZE - 1) {
			strcpy(cw[*cc], w[i]);
			(*cc)++;
		}
		if (strlen(w[i]) == JONG_SIZE - 1) {
			strcpy(jw[*jc], w[i]);
			(*jc)++;
		}
		if (strlen(w[i]) == GO_SIZE - 1) {
			strcpy(gw[*gc], w[i]);
			(*gc)++;
		}
	}
	fclose(f);
}

//------------------------문자열 표시하기------------------------------------

void show_chostring(char* w, char (*cw)[CHO_SIZE], int c) {
	int shift = rand() % c;
	strcpy(w, cw[shift]);
	gotoxy(55, 1); printf("%s\n", w);
}
void show_jongstring(char* w, char (*jw)[JONG_SIZE], int c) {
	int shift = rand() % c;
	strcpy(w, jw[shift]);
	gotoxy(55, 1); printf("%s\n", w);
}

void show_gostring(char* w, char(*gw)[GO_SIZE], int c) {
	int shift = rand() % c;
	strcpy(w, gw[shift]);

	gotoxy(55, 1); printf("%s\n", w);
}

//-----------------------문자열 맞추기----------------------------------------

int cho_practice(char(*cw)[CHO_SIZE], int c, int target_score) {
	system("cls");
	char word[CHO_SIZE], ch, input[CHO_SIZE];
	int s_time, j = 0;
	int score = 0;

	gotoxy(70, 1); printf("score: %d", score);
	srand(time(0));
	show_chostring(word, cw, c);
	s_time = time(0);
	while (1) {
		gotoxy(55 + j, 2);
		if (time(0) == s_time + CHO_TIME_LIMIT) {
			system("cls");
			gotoxy(70, 1); printf("score: %d", score);
			show_chostring(word, cw, c);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				break;
			}
			if (ch >= 'a' && ch <= 'z') {
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == 8) {
				j--;
				printf("\b \b");
				if (j <= 0) {
					j = 0;
				}
			}
		}

		if (j >= CHO_SIZE - 1) {
			input[CHO_SIZE - 1] = 0;
			if (!strcmp(word, input)) {
				//gotoxy(55, 3); printf("축하합니다.\n");
				score++;
				//Sleep(1000);
			}
			system("cls");
			gotoxy(70, 1); printf("score: %d", score);
			show_chostring(word, cw, c);
			s_time = time(0);
			j = 0;
		}
		if (score == target_score) {
			system("cls");
			//gotoxy(55, 3); printf("탈출 성공\n");
			//Sleep(1000);
			return 1;
		}
	}
}

void jong_practice(char(*jw)[JONG_SIZE], int c) {
	system("cls");
	char word[JONG_SIZE], ch, input[JONG_SIZE];
	int s_time, j = 0;
	int score = 0;

	gotoxy(70, 1); printf("score: %d", score);
	srand(time(0));
	show_jongstring(word, jw, c);
	s_time = time(0);
	while (1) {
		gotoxy(55 + j, 2);
		if (time(0) == s_time + JONG_TIME_LIMIT) {
			system("cls");
			gotoxy(70, 1); printf("score: %d", score);
			show_jongstring(word, jw, c);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				break;
			}
			if (ch >= 'a' && ch <= 'z') {
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == 8) {
				j--;
				printf("\b \b");
				if (j <= 0) {
					j = 0;
				}
			}
		}

		if (j >= JONG_SIZE - 1) {
			input[JONG_SIZE - 1] = 0;
			if (!strcmp(word, input)) {
				gotoxy(55, 3); printf("축하합니다.\n");
				score++;
				Sleep(1000);
			}
			system("cls");
			gotoxy(70, 1); printf("score: %d", score);
			show_jongstring(word, jw, c);
			s_time = time(0);
			j = 0;
		}
		if (score == 3) {
			system("cls");
			gotoxy(55, 3); printf("탈출 성공\n");
			Sleep(2000);
			break;
		}
	}
}
void go_practice(char(*gw)[GO_SIZE], int c) {
	system("cls");
	char word[GO_SIZE], ch, input[GO_SIZE];
	int s_time, j = 0;
	int score = 0;

	gotoxy(70, 1); printf("score: %d", score);
	srand(time(0));
	show_gostring(word, gw, c);
	s_time = time(0);
	while (1) {
		gotoxy(55 + j, 2);
		if (time(0) == s_time + GO_TIME_LIMIT) {
			system("cls");
			gotoxy(70, 1); printf("score: %d", score);
			show_gostring(word, gw, c);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				break;
			}
			if (ch >= 'a' && ch <= 'z') {
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == 8) {
				j--;
				printf("\b \b");
				if (j <= 0) {
					j = 0;
				}
			}
		}
		if (j >= GO_SIZE - 1) {
			input[GO_SIZE - 1] = 0;
			if (!strcmp(word, input)) {
				gotoxy(55, 3); printf("축하합니다.\n");
				score++;
				Sleep(1000);
			}
			system("cls");
			gotoxy(70, 1); printf("score: %d", score);
			show_gostring(word, gw, c);
			s_time = time(0);
			j = 0;
		}
		if (score == 3) {
			system("cls");
			gotoxy(55, 3); printf("탈출 성공\n");
			Sleep(2000);
			break;
		}
	}
}