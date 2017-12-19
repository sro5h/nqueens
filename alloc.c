#include "alloc.h"

#include <stdlib.h>

int** allocBoard(const int size)
{
        int **board = (int **) calloc(size, sizeof(int *));

        if (!board)
        {
                return NULL;
        }

        for (int i = 0; i < size; ++i)
        {
                board[i] = (int *) calloc(size, sizeof(int *));

                if (!board[i])
                {
                        return NULL;
                }
        }

        return board;
}

void freeBoard(int **board, const int size)
{
        for (int i = 0; i < size; ++i)
        {
                free(board[i]);
        }

        free(board);
}
