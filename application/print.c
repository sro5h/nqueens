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

void printMenu(int iSolving);
void printStatus(const struct nQueens * const pnQueens);

void print(const struct nQueens * const pnQueens)
{
        _clrscr();

        printMenu(pnQueens->iShouldSolve);
        printStatus(pnQueens);
}

void printBoard(int ** const ppiBoard, const int iN)
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

void printMenu(int algorithmRunning)
{
        _gotoxy(0, 0);

        printf(" ------------------------------------------------------------------------------\n");
        printf(" |                                   nQueens                                  |\n");
        printf(" ------------------------------------------------------------------------------\n");

        if (algorithmRunning)
        {
                printf("  [e]xit   [s]top                                                              \n");
        }
        else
        {
                printf("  [e]xit   [b]egin   s[a]ve mode   app [m]ode   change [f]ile                  \n");
        }
}

void printStatus(const struct nQueens * const pnQueens)
{
        _gotoxy(0, SCREEN_HEIGHT - STATUS_HEIGHT);

        printf(" ------------------------------------------------------------------------------\n");

        printf(" | Status: ");

        /* Save mode status */
        printf("save mode ");
        if (pnQueens->eSaveMode == SaveOn)
        {
                printf("(on)   ");
        }
        else
        {
                printf("(off)  ");
        }

        /* App mode status */
        printf("app mode ");
        if (pnQueens->eAppMode == Step)
        {
                printf("(Step)  ");
        }
        else
        {
                printf("(Cont)  ");
        }

        printf("\n");

        printf(" ------------------------------------------------------------------------------");
}
