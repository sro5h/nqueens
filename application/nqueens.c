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
