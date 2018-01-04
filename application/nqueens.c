#include <stdlib.h>
#include <string.h>
#include "nqueens.h"

void init(struct nQueens * const psnQueens)
{
        psnQueens->ppiBoard = NULL;
        psnQueens->iSize = 4;
        strncpy(psnQueens->acFilename, "default.txt", sizeof(psnQueens->acFilename));

        psnQueens->eAppMode = Step;
        psnQueens->eSaveMode = SaveOff;
        psnQueens->iShouldClose = 0;
        psnQueens->iShouldSolve = 0;

        psnQueens->sAppTime.lLastTimeStamp = clock();
        psnQueens->sAppTime.dRuntime = 0.0;

        psnQueens->iSolutionCount = 0;
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
