#include "alloc.h"
#include "solve.h"

#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 4

int main(int argc, char *argv[])
{
        int **ppiBoard = allocBoard(BOARD_SIZE);

        if (!ppiBoard)
        {
                printf("Allocation failed, aborting...\n");
                return -1;
        }

        solve(0, ppiBoard, BOARD_SIZE);

        freeBoard(ppiBoard, BOARD_SIZE);

        return 0;
}
