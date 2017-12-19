#include "print.h"

#define CHAR_NONE  '0'
#define CHAR_QUEEN '1'

#include <stdio.h>

void printBoard(int **board, const int n)
{
        for (int r = 0; r < n; ++r)
        {
                for (int c = 0; c < n; ++c)
                {
                        if (board[r][c])
                        {
                                printf(" %c ", CHAR_QUEEN);
                        }
                        else
                        {
                                printf(" %c ", CHAR_NONE);
                        }
                }

                printf("\n");
        }

        printf("\n");
}
