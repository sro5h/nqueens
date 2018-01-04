/**
 * @file nqueens.c
 * @brief Handles initializing and resetting the nQueens data.
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "nqueens.h"

void init(struct nQueens * const psnQueens)
{
        psnQueens->ppiBoard = NULL;
        psnQueens->iSize = DEFAULT_BOARD_SIZE;
        strncpy(psnQueens->acFilename, DEFAULT_FILENAME, sizeof(psnQueens->acFilename));

        psnQueens->eAppMode = Step;
        psnQueens->eSaveMode = SaveOff;
        psnQueens->iShouldClose = 0;
        psnQueens->iShouldSolve = 0;

        psnQueens->sAppTime.lLastTimeStamp = clock();
        psnQueens->sAppTime.dRuntime = 0.0;

        psnQueens->iSolutionCount = 0;

        // Set console buffer size
        HANDLE sHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD sBufferSize = { 80, 25 };
        SetConsoleScreenBufferSize(sHandle, sBufferSize);
        // Set console window size
        SMALL_RECT sWindowSize = { 0, 0, 80, 25 };
        SetConsoleWindowInfo(sHandle, 1, &sWindowSize);
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
