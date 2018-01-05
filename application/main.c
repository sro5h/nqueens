/**
 * @file main.c
 * @brief Handles the logical process of the program.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <save.h>
#include "nqueens.h"
#include "alloc.h"
#include "solve.h"
#include "print.h"
#include "input.h"
#include "runtime.h"

/**
 * @brief The main function
 * @return 0 if execution successful, -1 otherwise
 * @author Paul Meffle
 * @date 04.01.2018
 */
int main()
{
        struct nQueens snQueens;
        init(&snQueens);

        snQueens.ppiBoard = allocBoard(snQueens.iSize);

        if (!snQueens.ppiBoard)
        {
                printf("Allocation failed, aborting...\n");
                return -1;
        }

        while (!snQueens.iShouldClose)
        {
                print(&snQueens);

                if (snQueens.iShouldSolve)
                {
                        // Clear the file first if save mode is on
                        if (snQueens.eSaveMode == SaveOn)
                        {
                                resetFile(snQueens.acFilename);
                        }

                        // Begin runtime measurements
                        resetTime(&snQueens.sAppTime);

                        solve(0, &snQueens);

                        if (snQueens.eAppMode == Continuous && snQueens.iShouldSolve)
                        {
                                printSolutionCount(snQueens.iSolutionCount);
                                awaitInputSolve(&snQueens);
                        }

                        // Reset all solving related attributes
                        // Prevent from solving again if all solutions were found
                        snQueens.iShouldSolve = 0;
                        snQueens.iSolutionCount = 0;
                        resetTime(&snQueens.sAppTime);
                        resetBoard(snQueens.ppiBoard, snQueens.iSize);
                }
                else
                {
                        awaitInput(&snQueens);
                }
        }

        if (snQueens.ppiBoard)
        {
                freeBoard(snQueens.ppiBoard, snQueens.iSize);
        }

        return 0;
}
