#include "nqueens.h"

#include <stdlib.h>

void init(struct nQueens * const pnQueens)
{
        pnQueens->ppiBoard = NULL;
        pnQueens->iSize = 4;

        pnQueens->eAppMode = Step;
        pnQueens->eSaveMode = SaveOff;
        pnQueens->iShouldClose = 0;
        pnQueens->iShouldSolve = 0;

        pnQueens->iSolutionCount = 0;
}

void resetBoard(int ** const ppiBoard, const int iSize)
{
        for (int iRow = 0; iRow < iSize; ++iRow)
        {
                for (int iCol = 0; iCol < iSize; ++iCol)
                {
                        ppiBoard[iRow][iCol] = 0;
                }
        }
}
