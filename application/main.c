#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <utilities.h>
#include "alloc.h"
#include "solve.h"
#include "print.h"
#include "nqueens.h"

#define BOARD_SIZE 4

void handleInput(char cKey, struct nQueens * const pnQueens);

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

                printMenu();
                printBoard(snQueens.ppiBoard, snQueens.iSize);
                printStatus(&snQueens);

                char c = _getch();
                handleInput(c, &snQueens);
        }

        freeBoard(snQueens.ppiBoard, snQueens.iSize);

        return 0;
}

void handleInput(char cKey, struct nQueens * const pnQueens)
{
        switch (cKey)
        {
                case 'e':
                        pnQueens->iShouldClose = 1;
                        break;

                case 's':
                        pnQueens->iShouldClose = 1;
                        break;

                case 'c':
                        pnQueens->eSaveMode = pnQueens->eSaveMode == SaveOn ? SaveOff : SaveOn;
                        break;
        }
}
