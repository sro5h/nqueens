#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <utilities.h>
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
                _clrscr();

                printMenu(snQueens.iShouldSolve);
                printStatus(&snQueens);

                if (snQueens.iShouldSolve)
                {
                        solve(0, &snQueens);
                }

                awaitInput(&snQueens);
        }

        freeBoard(snQueens.ppiBoard, snQueens.iSize);

        return 0;
}
