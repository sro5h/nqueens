#include "util.h"

#include <stdio.h>

void gotoxy(int iX, int iY)
{
        printf("%c[%d;%df", 0x1B, iY, iX);
}

void clrscr()
{
        printf("\033[H\033[J");
}
