/**
 * @file print.c
 * @brief Handles printing the header, menu, body and status line.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <stdio.h>
#include <utilities.h>
#include "print.h"
#include "nqueens.h"

/**
 * @brief The character representing an empty field
 */
#define CHAR_NONE  '#'

/**
 * @brief The character representing a queen
 */
#define CHAR_QUEEN 'Q'

/**
 * @brief The height of the screen
 */
#define SCREEN_HEIGHT 25

/**
 * @brief The width of the screen
 */
#define SCREEN_WIDTH  80

/**
 * @brief The height of the menu
 */
#define MENU_HEIGHT   4

/**
 * @brief The height of the status line
 */
#define STATUS_HEIGHT 4

/**
 * @brief A helper function that prints the app header
 * @author Paul Meffle
 * @date 04.01.2018
 */
void printHeader();

/**
 * @brief A helper function that prints the menu
 * @param iSolving Whether solve is currently running
 * @author Paul Meffle
 * @date 04.01.2018
 */
void printMenu(int iSolving);

/**
 * @brief A helper function that sets the cursor to the screen end
 * @author Paul Meffle
 * @date 04.01.2018
 */
void gotoEnd();

void print(const struct nQueens * const psnQueens)
{
        _clrscr();

        printMenu(psnQueens->iShouldSolve);
        printStatus(psnQueens);
}

void printMessage(const char *pcMessage, const struct nQueens * const psnQueens)
{
        _clrscr();

        printStatus(psnQueens);
        printHeader();
        printf("  %s", pcMessage);
}

void printBoard(int ** const ppiBoard, const int iSize)
{
        const short iStartX = (SCREEN_WIDTH - 2 * (short)iSize) / 2;
        const short iStartY = MENU_HEIGHT + ((SCREEN_HEIGHT - STATUS_HEIGHT - MENU_HEIGHT - (short)iSize) / 2);

        for (int iR = 0; iR < iSize; ++iR)
        {
                _gotoxy(iStartX, iStartY + (short)iR);

                for (int iC = 0; iC < iSize; ++iC)
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
        const short iStartX = (SCREEN_WIDTH - 24) / 2;
        const short iStartY = MENU_HEIGHT + ((SCREEN_HEIGHT - STATUS_HEIGHT - MENU_HEIGHT - 2) / 2);

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
        printf("save mode: ");
        if (psnQueens->eSaveMode == SaveOn)
        {
                printf("on     ");
        }
        else
        {
                printf("off    ");
        }

        /* App mode status */
        printf("app mode: ");
        if (psnQueens->eAppMode == Step)
        {
                printf("step    ");
        }
        else
        {
                printf("cont    ");
        }

        /* Filename status */
        printf("filename: %.18s", psnQueens->acFilename);

        /* Print ending bar */
        _gotoxy(SCREEN_WIDTH - 2, SCREEN_HEIGHT - STATUS_HEIGHT + 1);
        printf("|\n");

        printf(" |         ");

        /* Board size status */
        printf("board size: %2d    ", psnQueens->iSize);

        /* Solution count  status */
        printf("solutions: %5d  ", psnQueens->iSolutionCount);

        /* Runtime in seconds status */
        printf("runtime: %.3lfs", psnQueens->sAppTime.dRuntime);

        /* Print ending bar */
        _gotoxy(SCREEN_WIDTH - 2, SCREEN_HEIGHT - STATUS_HEIGHT + 2);
        printf("|\n");

        printf(" ------------------------------------------------------------------------------");
}

void gotoEnd()
{
        _gotoxy(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
}
