#include <stdio.h>
#include <conio.h>
#include "input.h"
#include "print.h"

#define KEY_STOP 1

void awaitInput(struct nQueens * const pnQueens)
{
        char cKey = _getch();
        int iNewSize;

        switch (cKey)
        {
        case 'e':
                pnQueens->iShouldClose = 1;
                break;

        case 'b':
                pnQueens->iShouldSolve = 1;
                break;

        case 'a':
                pnQueens->eSaveMode = pnQueens->eSaveMode == SaveOn ? SaveOff : SaveOn;
                break;

        case 'm':
                pnQueens->eAppMode = pnQueens->eAppMode == Step ? Continuous : Step;
                break;

        case 's':
                do
                {
                        printInputScreen("  Enter new board size: ", pnQueens);
                        scanf("%d", &iNewSize);
                }
                while (!(iNewSize >= 4 && iNewSize <= 12));

                freeBoard(pnQueens->ppiBoard, pnQueens->iSize);
                pnQueens->iSize = iNewSize;
                pnQueens->ppiBoard = allocBoard(pnQueens->iSize);

                // Terminate the program if allocation failed
                if (pnQueens->ppiBoard == NULL)
                {
                        pnQueens->iShouldClose = 1;
                }

                break;
        }
}

void awaitInputSolve(struct nQueens * const pnQueens)
{
        char cKey = _getch();

        switch (cKey)
        {
        case 'e':
                pnQueens->iShouldSolve = 0;
                pnQueens->iShouldClose = 1;
                break;

        case 's':
                pnQueens->iShouldSolve = 0;
                break;

        /* Continue if a key is hit */
        default:
                break;
        }
}

int checkInputSolve(struct nQueens * const pnQueens)
{
        if (_kbhit())
        {
                char cKey = _getch();

                switch (cKey)
                {
                case 'e':
                        pnQueens->iShouldSolve = 0;
                        pnQueens->iShouldClose = 1;
                        return KEY_STOP;

                case 's':
                        pnQueens->iShouldSolve = 0;
                        return KEY_STOP;
                }
        }

        return 0;
}