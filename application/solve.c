/**
 * @file solve.c
 * @brief Handles solving the n queens problem.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <save.h>
#include "solve.h"
#include "print.h"
#include "runtime.h"

/**
 * @brief A helper function that checks whether a field is safe
 * @param iRow The row to check
 * @param iCol The column to check
 * @param ppiBoard The array containing the chess board
 * @param iSize The size of the array
 * @return 1 if the field is safe, 0 otherwise
 * @author Paul Meffle
 * @date 04.01.2018
 */
int isSafe(const int iRow, const int iCol, int ** const ppiBoard, const int iSize);

/**
 * @brief A helper function that handles a found solution
 * @param psnQueens The current app state
 * @author Paul Meffle
 * @date 04.01.2018
 */
void handleSolution(struct nQueens * const psnQueens);

int solve(const int iRow, struct nQueens * const psnQueens)
{
        // Return true if n queens could be placed
        if (iRow == psnQueens->iSize)
        {
                ++psnQueens->iSolutionCount;

                handleSolution(psnQueens);

                // Is the user requesting to stop solving
                if (!psnQueens->iShouldSolve)
                {
                        return -1;
                }

                return 1;
        }

        for (int iC = 0; iC < psnQueens->iSize; ++iC)
        {
                if (isSafe(iRow, iC, psnQueens->ppiBoard, psnQueens->iSize))
                {
                        psnQueens->ppiBoard[iRow][iC] = 1;

                        // Propagate the stop request down the recursion tree
                        if (solve(iRow + 1, psnQueens) == -1)
                        {
                                return -1;
                        }

                        psnQueens->ppiBoard[iRow][iC] = 0;
                }
        }

        return 0;
}

void handleSolution(struct nQueens * const psnQueens)
{
        // Save solution to file if save mode is on
        if (psnQueens->eSaveMode == SaveOn)
        {
                appendToFile(psnQueens->acFilename, psnQueens->ppiBoard,
                        psnQueens->iSize, psnQueens->iSolutionCount);
        }

        // Update the status line
        printStatus(psnQueens);

        // Append the measured time to dRuntime
        // The time spent on printing and saving is intentionally added
        // as it is not further specified.
        appendElapsed(&psnQueens->sAppTime);

        if (psnQueens->eAppMode == Step)
        {
                printBoard(psnQueens->ppiBoard, psnQueens->iSize);
                awaitInputSolve(psnQueens);

                // Discard the time that got spent on waiting for input
                discardElapsed(&psnQueens->sAppTime);
        }
        else
        {
                checkInputSolve(psnQueens);
        }
}

int isSafe(const int iRow, const int iCol, int ** const ppiBoard, const int iSize)
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
        for (int iR = iRow, iC = iCol; iR >= 0 && iC < iSize; --iR, ++iC)
        {
                if (ppiBoard[iR][iC])
                {
                        return 0;
                }
        }

        return 1;
}
