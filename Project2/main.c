#include "startScreen.h"
#include "loginScreen.h"
#include "GameInfo.h"
#include "user.h"
#include "ladder.h"
#include "util.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(void) {
    struct User* user;
    srand(time(NULL));
    hide_cursor();
    titleDraw();
    menuDraw();
    return 0;
}