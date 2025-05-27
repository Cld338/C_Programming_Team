#ifndef WORD_H
#define WORD_H

#define NUM 10000

#define CHO_TIME_LIMIT 10
#define JONG_TIME_LIMIT 7
#define GO_TIME_LIMIT 5

#define CHO_SIZE 6
#define JONG_SIZE 8
#define GO_SIZE 11

void make_list(char*, char*, char*, char*, int*, int*, int*);

void show_chostring(char*, char*, int);
void show_jongstring(char*, char*, int);
void show_gostring(char*, char*, int);

int cho_practice(char*, int);
void jong_practice(char*, int);
void go_practice(char*, int);

#endif