#include "alloc.h"

#include <stdlib.h>

int** allocBoard(const int iSize)
{
        int **ppiBoard = (int **) calloc(iSize, sizeof(int *));

        if (!ppiBoard)
        {
                return NULL;
        }

        for (int i = 0; i < iSize; ++i)
        {
                ppiBoard[i] = (int *) calloc(iSize, sizeof(int *));

                if (!ppiBoard[i])
                {
                        return NULL;
                }
        }

        return ppiBoard;
}

void freeBoard(int **ppiBoard, const int iSize)
{
        for (int i = 0; i < iSize; ++i)
        {
                free(ppiBoard[i]);
        }

        free(ppiBoard);
}
