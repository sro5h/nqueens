#include "print.h"
#include "util.h"

#include <stdio.h>

#define CHAR_NONE  '0'
#define CHAR_QUEEN '1'

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH  80
#define MENU_HEIGHT   3
#define STATUS_HEIGHT 3

void printBoard(int **ppiBoard, const int iN)
{
        const int iStartX = (SCREEN_WIDTH - 3 * iN) / 2;
        const int iStartY = (SCREEN_HEIGHT - iN) / 2;

        for (int iR = 0; iR < iN; ++iR)
        {
                gotoxy(iStartX, iStartY + iR);

                for (int iC = 0; iC < iN; ++iC)
                {
                        if (ppiBoard[iR][iC])
                        {
                                printf(" %c ", CHAR_QUEEN);
                        }
                        else
                        {
                                printf(" %c ", CHAR_NONE);
                        }
                }
        }
}

void printMenu()
{
        gotoxy(0, 0);

        printf("--------------------------------------------------------------------------------\n");
        printf("|                                    nQueens                                   |\n");
        printf("--------------------------------------------------------------------------------\n");
}

void printStatus()
{
        gotoxy(0, SCREEN_HEIGHT - STATUS_HEIGHT);

        printf("--------------------------------------------------------------------------------\n");
        printf("| Status: ready.                                                               |\n");
        printf("--------------------------------------------------------------------------------\n");
}
