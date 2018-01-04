#include <stdio.h>
#include <conio.h>
#include "input.h"
#include "print.h"

#define KEY_STOP 1

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
                printInputScreen("Enter new filename: ", psnQueens);
                scanf("%s", acBuffer);

                strncpy(psnQueens->acFilename, acBuffer, sizeof(psnQueens->acFilename));
                break;

        case 's':
                do
                {
                        printInputScreen("Enter new board size: ", psnQueens);
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