#include "solve.h"
#include "print.h"

int isSafe(const int iRow, const int iCol, int ** const ppiBoard, const int iN);

int solve(const int iRow, struct nQueens * const pnQueens)
{
        // Return true if n queens could be placed
        if (iRow == pnQueens->iSize)
        {
                printBoard(pnQueens->ppiBoard, pnQueens->iSize);
                awaitInputSolve(pnQueens);
                return 1;
        }

        for (int iC = 0; iC < pnQueens->iSize; ++iC)
        {
                if (isSafe(iRow, iC, pnQueens->ppiBoard, pnQueens->iSize))
                {
                        pnQueens->ppiBoard[iRow][iC] = 1;

                        solve(iRow + 1, pnQueens);

                        pnQueens->ppiBoard[iRow][iC] = 0;
                }
        }

        return 0;
}

int isSafe(const int iRow, const int iCol, int ** const ppiBoard, const int iN)
{
        // Check above
        for (int iR = 0; iR < iRow; ++iR)
        {
                if (ppiBoard[iR][iCol])
                {
                        return 0;
                }
        }

        // Check diagonal top left
        for (int iR = iRow, iC = iCol; iR >= 0 && iC >= 0; --iR, --iC)
        {
                if (ppiBoard[iR][iC])
                {
                        return 0;
                }
        }

        // Check diagonal top right
        for (int iR = iRow, iC = iCol; iR >= 0 && iC < iN; --iR, ++iC)
        {
                if (ppiBoard[iR][iC])
                {
                        return 0;
                }
        }

        return 1;
}
