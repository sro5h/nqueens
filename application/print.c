#include <utilities.h>
#include "print.h"
#include "nqueens.h"

#include <stdio.h>

#define CHAR_NONE  '#'
#define CHAR_QUEEN 'Q'

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH  80
#define MENU_HEIGHT   4
#define STATUS_HEIGHT 4

void printHeader();
void printMenu(int iSolving);
void gotoEnd();

void print(const struct nQueens * const psnQueens)
{
        _clrscr();

        printMenu(psnQueens->iShouldSolve);
        printStatus(psnQueens);
}

void printInputScreen(const char *pcMessage, const struct nQueens * const psnQueens)
{
        _clrscr();

        printStatus(psnQueens);
        printHeader();
        printf("  %s", pcMessage);
}

void printBoard(int ** const ppiBoard, const int iN)
{
        const int iStartX = (SCREEN_WIDTH - 2 * iN) / 2;
        const int iStartY = MENU_HEIGHT + ((SCREEN_HEIGHT - STATUS_HEIGHT - MENU_HEIGHT - iN) / 2);

        for (int iR = 0; iR < iN; ++iR)
        {
                _gotoxy(iStartX, iStartY + iR);

                for (int iC = 0; iC < iN; ++iC)
                {
                        if (ppiBoard[iR][iC])
                        {
                                printf(" %c", CHAR_QUEEN);
                        }
                        else
                        {
                                printf(" %c", CHAR_NONE);
                        }
                }
        }

        gotoEnd();
}

void printSolutionCount(const int iSolutionCount)
{
        const int iStartX = (SCREEN_WIDTH - 24) / 2;
        const int iStartY = MENU_HEIGHT + ((SCREEN_HEIGHT - STATUS_HEIGHT - MENU_HEIGHT - 2) / 2);

        _gotoxy(iStartX, iStartY);
        printf("Solutions found: %5d\n", iSolutionCount);
        _gotoxy(iStartX, iStartY + 1);
        printf("Press any key to continue...\n");

        gotoEnd();
}

void printHeader()
{
        _gotoxy(0, 0);

        printf(" ------------------------------------------------------------------------------\n");
        printf(" |                                   nQueens                                  |\n");
        printf(" ------------------------------------------------------------------------------\n");
}

void printMenu(int algorithmRunning)
{
        printHeader();

        if (algorithmRunning)
        {
                printf("  [e]xit   [s]top                                                              \n");
        }
        else
        {
                printf("  [e]xit   [b]egin   s[a]ve mode   app [m]ode   change [f]ile   board [s]ize   \n");
        }
}

void printStatus(const struct nQueens * const psnQueens)
{
        _gotoxy(0, SCREEN_HEIGHT - STATUS_HEIGHT);

        printf(" ------------------------------------------------------------------------------\n");

        printf(" | Status: ");

        /* Save mode status */
        printf("save mode ");
        if (psnQueens->eSaveMode == SaveOn)
        {
                printf("(on)   ");
        }
        else
        {
                printf("(off)  ");
        }

        /* App mode status */
        printf("app mode ");
        if (psnQueens->eAppMode == Step)
        {
                printf("(Step)  ");
        }
        else
        {
                printf("(Cont)  ");
        }

        /* Filename status */
        printf("filename (%.20s)", psnQueens->acFilename);

        /* Print ending bar */
        _gotoxy(SCREEN_WIDTH - 2, SCREEN_HEIGHT - STATUS_HEIGHT + 1);
        printf("|\n");

        printf(" |         ");

        /* Board size status */
        printf("board size (%d)   ", psnQueens->iSize);

        /* Solution count  status */
        printf("solutions (%d)   ", psnQueens->iSolutionCount);

        /* Print ending bar */
        _gotoxy(SCREEN_WIDTH - 2, SCREEN_HEIGHT - STATUS_HEIGHT + 2);
        printf("|\n");

        printf(" ------------------------------------------------------------------------------");
}

void gotoEnd()
{
        _gotoxy(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
}
