#include "alloc.h"
#include "solve.h"
#include "print.h"
#include "util.h"

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

        clrscr();

        printMenu();
        printStatus();

        freeBoard(ppiBoard, BOARD_SIZE);

        return 0;
}
