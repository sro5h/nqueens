#include "util.h"

void gotoxy(int x, int y)
{
        printf("%c[%d;%df", 0x1B, y, x);
}

void clrscr()
{
        printf("\033[H\033[J");
}
