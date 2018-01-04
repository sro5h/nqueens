/**
 * @file input.c
 * @brief Handles user input and reacts to it
 * @author Paul Meffle
 * @date 04.01.2018
 */

#include <stdio.h>
#include <conio.h>
#include "input.h"
#include "print.h"

void awaitInput(struct nQueens * const psnQueens)
{
        char cKey = _getch();
        int iNewSize;
        char acBuffer[64];

        switch (cKey)
        {
        case 'e':
                psnQueens->iShouldClose = 1;
                break;

        case 'b':
                psnQueens->iShouldSolve = 1;
                break;

        case 'a':
                psnQueens->eSaveMode = psnQueens->eSaveMode == SaveOn ? SaveOff : SaveOn;
                break;

        case 'm':
                psnQueens->eAppMode = psnQueens->eAppMode == Step ? Continuous : Step;
                break;

        case 'f':
                printMessage("Enter new filename: ", psnQueens);
                scanf("%s", acBuffer);

                strncpy(psnQueens->acFilename, acBuffer, sizeof(psnQueens->acFilename));
                break;

        case 's':
                do
                {
                        printMessage("Enter new board size: ", psnQueens);
                        scanf("%s", acBuffer);
                        iNewSize = (int) strtol(acBuffer, NULL, 10);
                }
                while (!(iNewSize >= 4 && iNewSize <= 12));

                freeBoard(psnQueens->ppiBoard, psnQueens->iSize);
                psnQueens->iSize = iNewSize;
                psnQueens->ppiBoard = allocBoard(psnQueens->iSize);

                // Terminate the program if allocation failed
                if (psnQueens->ppiBoard == NULL)
                {
                        psnQueens->iShouldClose = 1;
                }
                break;
        }
}

void awaitInputSolve(struct nQueens * const psnQueens)
{
        char cKey = _getch();

        switch (cKey)
        {
        case 'e':
                psnQueens->iShouldSolve = 0;
                psnQueens->iShouldClose = 1;
                break;

        case 's':
                psnQueens->iShouldSolve = 0;
                break;

        /* Continue if a key is hit */
        default:
                break;
        }
}

void checkInputSolve(struct nQueens * const psnQueens)
{
        if (_kbhit())
        {
                awaitInputSolve(psnQueens);
        }
}
