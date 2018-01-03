#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "nqueens.h"
#include "alloc.h"
#include "solve.h"
#include "print.h"
#include "input.h"

#define BOARD_SIZE 4

int main(int argc, char *argv[])
{
        struct nQueens snQueens;
        init(&snQueens);

        snQueens.iSize = BOARD_SIZE;
        snQueens.ppiBoard = allocBoard(BOARD_SIZE);

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
                        solve(0, &snQueens);

                        if (snQueens.eAppMode == Continuous && snQueens.iShouldSolve)
                        {
                                printSolutionCount(snQueens.iSolutionCount);
                                awaitInputSolve(&snQueens);
                        }

                        // Prevent from solving again if all solutions were found
                        snQueens.iShouldSolve = 0;
                        snQueens.iSolutionCount = 0;

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
