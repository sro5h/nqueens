#include "alloc.h"
#include "print.h"

#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 4

int isSafe(int row, int col, int **array, int n)
{
        // Check above
        for (int r = 0; r < row; ++r) {
                if (array[r][col]) {
                        return 0;
                }
        }

        // Check diagonal top left
        for (int r = row, c = col; r >= 0 && c >= 0; --r, --c) {
                if (array[r][c]) {
                        return 0;
                }
        }

        // Check diagonal top right
        for (int r = row, c = col; r >= 0 && c < n; --r, ++c) {
                if (array[r][c]) {
                        return 0;
                }
        }

        return 1;
}


int main(int argc, char *argv[])
{
        int **board = allocBoard(BOARD_SIZE);

        if (!board) {
                printf("Allocation failed, aborting...\n");
                return -1;
        }

        board[0][1] = 1;

        printBoard(board, BOARD_SIZE);

        if (isSafe(1, 3, board, BOARD_SIZE)) {
                board[1][3] = 1;
                printBoard(board, BOARD_SIZE);
        } else {
                printf("Not safe!\n");
        }

        freeBoard(board, BOARD_SIZE);

        return 0;
}
