#include <utilities.h>
#include "print.h"
#include "nqueens.h"

#include <stdio.h>

#define CHAR_NONE  '0'
#define CHAR_QUEEN '1'

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH  80
#define MENU_HEIGHT   4
#define STATUS_HEIGHT 3

void printBoard(int **ppiBoard, const int iN)
{
        const int iStartX = (SCREEN_WIDTH - 3 * iN) / 2;
        const int iStartY = (SCREEN_HEIGHT - iN) / 2;

        for (int iR = 0; iR < iN; ++iR)
        {
                _gotoxy(iStartX, iStartY + iR);

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
        _gotoxy(0, 0);

        printf(" ------------------------------------------------------------------------------\n");
        printf(" |                                   nQueens                                  |\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("  [e]xit   [s]top calculation   s[a]ve mode   change [f]ilename                \n");
}

void printStatus(const struct nQueens * const pnQueens)
{
        _gotoxy(0, SCREEN_HEIGHT - STATUS_HEIGHT);

        printf(" ------------------------------------------------------------------------------\n");

        printf(" | Status: ");
        printf("save mode ");

        if (pnQueens->eSaveMode == SaveOn)
        {
                printf("(on)  ");
        }
        else
        {
                printf("(off) ");
        }

        printf("\n");

        printf(" ------------------------------------------------------------------------------");
}
