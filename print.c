#include "print.h"
#include "util.h"

#include <stdio.h>

#define CHAR_NONE  '0'
#define CHAR_QUEEN '1'

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80
#define MENU_HEIGHT 3
#define STATUS_HEIGHT 3

void printBoard(int **ppiBoard, const int iN)
{
        for (int iR = 0; iR < iN; ++iR)
        {
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

                printf("\n");
        }

        printf("\n");
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
