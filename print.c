#include "print.h"

#define CHAR_NONE  '0'
#define CHAR_QUEEN '1'

#include <stdio.h>

void printBoard(int **ppiBoard, const int iN)
{
        for (int iR = 0; iR < iN; ++iR)
        {
                for (int iC = 0; iC < iN; ++iC)
                {
                        if (ppiBoard[iR][iC])
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
