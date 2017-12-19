#include "alloc.h"
#include "solve.h"

#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 4

int main(int argc, char *argv[])
{
        int **board = allocBoard(BOARD_SIZE);

        if (!board)
        {
                printf("Allocation failed, aborting...\n");
                return -1;
        }

        solve(0, board, BOARD_SIZE);

        freeBoard(board, BOARD_SIZE);

        return 0;
}
