#ifndef UTIL_H
#define UTIL_H

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void setColor(int color);
int keyControl();
void gotoxy(int x, int y);
void show_cursor();
void hide_cursor();

#endif
