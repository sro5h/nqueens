#include "alloc.h"
#include "print.h"

#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 4

int isSafe(const int row, const int col, int ** const array, const int n)
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

int solve(int row, int ** const board, const int size);

int main(int argc, char *argv[])
{
        int **board = allocBoard(BOARD_SIZE);

        if (!board) {
                printf("Allocation failed, aborting...\n");
                return -1;
        }

        if (!solve(0, board, BOARD_SIZE)) {
                printf("No solution found\n");
                return 0;
        }

        printBoard(board, BOARD_SIZE);

        freeBoard(board, BOARD_SIZE);

        return 0;
}

int solve(int row, int ** const board, const int size)
{
        // Return true if n queens could be placed
        if (row >= size) {
                return 1;
        }

        for (int c = 0; c < size; ++c) {
                if (isSafe(row, c, board, size)) {
                        board[row][c] = 1;

                        // Go back up the recursion tree
                        if (solve(row + 1, board, size)) {
                                return 1;
                        }

                        board[row][c] = 0;
                }
        }

        return 0;
}
