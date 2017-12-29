#include "alloc.h"
#include "solve.h"
#include "print.h"
#include "util.h"
#include "nqueens.h"

#include <stdlib.h>
#include <stdio.h>

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
                clrscr();

                printMenu();
                printBoard(snQueens.ppiBoard, snQueens.iSize);
                printStatus();

                getchar();
        }

        freeBoard(snQueens.ppiBoard, snQueens.iSize);

        return 0;
}
