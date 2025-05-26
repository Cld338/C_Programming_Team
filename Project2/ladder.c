#include "ladder.h" 
#include "util.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* char_mul(const char* string, int k) {
    static char result[30];
    result[0] = '\0';
    int current_len = 0;
    int segment_len = strlen(string);
    for (int i = 0; i < k; i++) {
        if (current_len + segment_len < sizeof(result)) {
            strcat(result, string);
            current_len += segment_len;
        }
        else {
            break;
        }
    }
    return result;
}

void check_ladder(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            printf("%d ", (*ladder_ptr)[i][j]);
        }
        printf("\n");
    }
}

void random_ladder(int* ptr) {
    if (rand() % 4 == 0) {
        *ptr = 2;
    }
    else {
        *ptr = 1;
    }
}

void make_path(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE], int row, int col) {
    int pos_row = ARR_SIZE - 1;
    int pos_col = 0;
    while (1) {
        if (pos_row == row && pos_col == col) {
            break; // ��� �ϼ�
        }
        int can_move_up = (pos_row > row);     // ���� �̵� ����
        int can_move_right = (pos_col < col); // ���������� �̵� ����
        if (!can_move_up && !can_move_right) {
            break;
        }
        int moved_this_iteration = 0;
        if (rand() % 2 == 0) { // 0�� ������: ���� �켱 �̵� �õ�
            if (can_move_up) {
                pos_row--;
                if (pos_row >= row) {
                    pos_row--;
                }
                else {
                    pos_row++;
                }
            }
            else if (can_move_right) { // ���� �̵��� �� ���ٸ� ���������� �̵� �õ�
                pos_col++;
                if (pos_col <= col) {
                    (*ladder_ptr)[pos_row][pos_col] = 1;
                    pos_col++;
                }
                else {
                    pos_col--;
                }
            }
        }
        else { // 1�� ������: ���������� �켱 �̵� �õ�
            if (can_move_right) {
                pos_col++;
                if (pos_col <= col) {
                    (*ladder_ptr)[pos_row][pos_col] = 1;
                    pos_col++;
                }
                else {
                    pos_col--;
                }
            }
            else if (can_move_up) { // ���������� �̵��� �� ���ٸ� ���� �̵� �õ�
                pos_row--;
                if (pos_row >= row) {
                    (*ladder_ptr)[pos_row][pos_col] = 1;
                    pos_row--;
                }
                else {
                    pos_row++;
                }
            }
        }
        if (!moved_this_iteration && (can_move_up || can_move_right)) {
        }
    }
}


void put_gem(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]) {
    int gem_count = 0;
    int row, col;
    while (gem_count < GEM_LIMIT) { // ���� ������ ���� ��ŭ �ֱ�
        row = rand() % LADDER_SIZE * 2;
        col = rand() % LADDER_SIZE * 2;
        if (rand() % 2 == 0) col++;
        else row++;
        // i, j�� Ȧ, ¦�̸� ���μ�, ¦, Ȧ�̸� ���μ�
        if ((*ladder_ptr)[row][col] == 1) {
            // ���� �ִ� ���� ���� ������ ������
            (*ladder_ptr)[row][col] = 2; // ���� �ֱ�
            gem_count++;
        }

    }
}
void create_ladder(int (*ladder_ptr)[ARR_SIZE][ARR_SIZE]) {
    int (*ladder)[ARR_SIZE] = *ladder_ptr;

    // �׳� �ƹ����� �� �߱�
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            if ((i % 2 == 0 && j % 2 == 1)) { // ������ ��ġ (i ¦��, j Ȧ��)
                if (rand() % 2 != 0) { // ���� ������ ����
                    (*ladder_ptr)[i][j] = 1;
                }
                else {
                    ladder[i][j] = 0;
                }
            }
            else if (i % 2 == 0 && j % 2 == 0) { // ������ ��ġ (i ¦��, j ¦��)
                ladder[i][j] = 1;
            }
            else if (i % 2 == 1 && j % 2 == 0) { // ������ ��ġ (i Ȧ��, j ¦��)
                (*ladder_ptr)[i][j] = 1;
            }
            else { // ���� ��ġ (i Ȧ��, j Ȧ��)
                ladder[i][j] = 0;
            }
        }
    }
    make_path(ladder_ptr, 0, ARR_SIZE - 1); // ���� ���� ���� �� �����
    put_gem(ladder_ptr);
}

void print_ladder(int ladder[ARR_SIZE][ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < ARR_SIZE; j++) {
                if (j % 2 == 0) {
                    printf("%s", VERTICAL_LINE_CHAR);
                }
                else {
                    if (ladder[i][j] == 1) {
                        printf("%s", char_mul(HORIZONTAL_LINE_CHAR, HORIZONTAL_LENGTH));
                    }
                    else if (ladder[i][j] == 2) {
                        setColor(4);
                        printf("%s", char_mul(HORIZONTAL_LINE_CHAR, HORIZONTAL_LENGTH));
                        setColor(15);
                    }
                    else {
                        printf("%s", char_mul(" ", HORIZONTAL_LENGTH));
                    }
                }
            }
            printf("\n");

        }
        else {
            for (int row_segment = 0; row_segment < VERTICAL_LENGTH; row_segment++) {
                for (int j = 0; j < ARR_SIZE; j++) {
                    if (j % 2 == 0) {
                        if (ladder[i][j] == 1) {
                            printf("%s", VERTICAL_LINE_CHAR);
                        }
                        else if (ladder[i][j] == 2) {
                            setColor(4);
                            printf("%s", VERTICAL_LINE_CHAR);
                            setColor(15);
                        }
                        else {
                            printf(" ");
                        }
                    }
                    else {
                        printf("%s", char_mul(" ", HORIZONTAL_LENGTH));
                    }
                }
                printf("\n");
            }
        }
    }
}


