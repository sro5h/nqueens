#include "print.h"

int isSafe(const int row, const int col, int ** const array, const int n);

int solve(const int row, int ** const board, const int size)
{
        // Return true if n queens could be placed
        if (row == size)
        {
                printBoard(board, size);
                return 1;
        }

        for (int c = 0; c < size; ++c)
        {
                if (isSafe(row, c, board, size))
                {
                        board[row][c] = 1;

                        solve(row + 1, board, size);

                        board[row][c] = 0;
                }
        }

        return 0;
}

int isSafe(const int row, const int col, int ** const array, const int n)
{
        // Check above
        for (int r = 0; r < row; ++r)
        {
                if (array[r][col])
                {
                        return 0;
                }
        }

        // Check diagonal top left
        for (int r = row, c = col; r >= 0 && c >= 0; --r, --c)
        {
                if (array[r][c])
                {
                        return 0;
                }
        }

        // Check diagonal top right
        for (int r = row, c = col; r >= 0 && c < n; --r, ++c)
        {
                if (array[r][c])
                {
                        return 0;
                }
        }

        return 1;
}
